#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>

auto move_box_left(std::pair<int, int> first_box_pos, std::vector<std::vector<char>>& grid)
{
    // so we need to find the sequence of boxes.
    std::pair<int, int> current_position = first_box_pos;
    int length = 0;
    bool carry_on = false;
    for(int i = current_position.second; i > 0; i--)
    {
        if(carry_on)
        {
            if(grid[current_position.first][i] == 'O')
            {
                length += 1;
            }
            else {
                carry_on = false;
            }
        }
    }
    // now that weve got the length of the thing we move. we can try move it.
    std::pair<int, int> furthest{current_position.first, current_position.second - length + 1};
    if(grid[furthest.first][furthest.second - 1] == '.')
    {
        // this means we can move it.
        for(int i = 0; i < length; i++)
        {
            grid[furthest.first][furthest.second - 1 + length] = grid[furthest.first][furthest.second + length];
            grid[furthest.first][furthest.second + length] = '.';
        }
    }
    else {
        // this means we cant move it, so we just leave it.
    }
}

auto move_box_right(std::pair<int, int> first_box_pos, std::vector<std::vector<char>>& grid)
{
    // so we need to find the sequence of boxes.
    std::pair<int, int> current_position = first_box_pos;
    int length = 0;
    bool carry_on = false;
    for(int i = current_position.second; i < grid[0].size(); i++)
    {
        if(carry_on)
        {
            if(grid[current_position.first][i] == 'O')
            {
                length += 1;
            }
            else {
                carry_on = false;
            }
        }
    }
    // now that weve got the length of the thing we move. we can try move it.
    std::pair<int, int> furthest{current_position.first, current_position.second + length - 1};
    if(grid[furthest.first][furthest.second + 1] == '.')
    {
        // this means we can move it.
        for(int i = 0; i < length; i++)
        {
            grid[furthest.first][furthest.second + 1 - length] = grid[furthest.first][furthest.second - length];
            grid[furthest.first][furthest.second + length] = '.';
        }
    }
    else {
        // this means we cant move it, so we just leave it.
    }
}

auto move_box_up(std::pair<int, int> first_box_pos, std::vector<std::vector<char>>& grid)
{
    // so we need to find the sequence of boxes.
    std::pair<int, int> current_position = first_box_pos;
    int length = 0;
    bool carry_on = false;
    for(int i = current_position.first; i > 0; i--)
    {
        if(carry_on)
        {
            if(grid[i][current_position.second] == 'O')
            {
                length += 1;
            }
            else {
                carry_on = false;
            }
        }
    }
    // now that weve got the length of the thing we move. we can try move it.
    std::pair<int, int> furthest{current_position.first - length + 1, current_position.second};
    if(grid[furthest.first - 1][furthest.second] == '.')
    {
        // this means we can move it.
        for(int i = 0; i < length; i++)
        {
            grid[furthest.first - 1 + length][furthest.second] = grid[furthest.first + length][furthest.second];
            grid[furthest.first + length][furthest.second] = '.';
        }
    }
    else {
        // this means we cant move it, so we just leave it.
    }
}

auto move_box_down(std::pair<int, int> first_box_pos, std::vector<std::vector<char>>& grid)
{
    // so we need to find the sequence of boxes.
    std::pair<int, int> current_position = first_box_pos;
    int length = 0;
    bool carry_on = false;
    for(int i = current_position.first; i < grid.size(); i++)
    {
        if(carry_on)
        {
            if(grid[i][current_position.second] == 'O')
            {
                length += 1;
            }
            else {
                carry_on = false;
            }
        }
    }
    // now that weve got the length of the thing we move. we can try move it.
    std::pair<int, int> furthest{current_position.first + length - 1, current_position.second};
    if(grid[furthest.first + 1][furthest.second] == '.')
    {
        // this means we can move it.
        for(int i = 0; i < length; i++)
        {
            grid[furthest.first + 1 - length][furthest.second] = grid[furthest.first - length][furthest.second];
            grid[furthest.first + length][furthest.second] = '.';
        }
    }
    else {
        // this means we cant move it, so we just leave it.
    }
}

int main()
{
    std::vector<std::vector<char>> grid{};
    std::vector<char> moves{};
    std::string line{};
    bool current = true;
    while(std::getline(std::cin, line) && line != "ENDOFLINE")
    {
        if(line == "")
        {
            current = false;
        }
        else if(current == true)
        {
            std::vector<char> vec{};
            for(auto x : line)
            {
                vec.push_back(x);
            }
            if(vec.size() != 0)
            {
                grid.push_back(vec);
            }
        }
        else if(current == false)
        {
            for(auto x : line)
            {
                moves.push_back(x);
            }
        }
    }

    // now get the position of the robot.
    bool found = false;
    std::pair<int, int> current_pos{};
    while(!found)
    {
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == '@')
                {
                    current_pos = std::pair{i, j};
                    found = true;
                }
            }
        }
    }

    // after we have the input, we need to operate the moves.
    for(auto x : moves)
    {
        if(x == '^')
        {
            // we move upwards
            if(grid[current_pos.first - 1][current_pos.second] == 'O')
            {
                move_box_up(std::pair{current_pos.first - 1, current_pos.second}, grid);
            }
            if(grid[current_pos.first - 1][current_pos.second] == '.')
            {
                current_pos = std::pair{current_pos.first - 1, current_pos.second};
            }
        }
        else if(x == 'v')
        {
            // we move downwards
            if(grid[current_pos.first + 1][current_pos.second] == 'O')
            {
                move_box_down(std::pair{current_pos.first + 1, current_pos.second}, grid);
            }
            if(grid[current_pos.first + 1][current_pos.second] == '.')
            {
                current_pos = std::pair{current_pos.first + 1, current_pos.second};
            }
        }
        else if(x == '<')
        {
            // we move left
            if(grid[current_pos.first][current_pos.second - 1] == 'O')
            {
                move_box_left(std::pair{current_pos.first, current_pos.second - 1}, grid);
            }
            if(grid[current_pos.first][current_pos.second - 1] == '.')
            {
                current_pos = std::pair{current_pos.first, current_pos.second - 1};
            }
        }
        else if(x == '>')
        {
            // we move right
             if(grid[current_pos.first][current_pos.second + 1] == 'O')
            {
                move_box_left(std::pair{current_pos.first, current_pos.second + 1}, grid);
            }
            if(grid[current_pos.first][current_pos.second + 1] == '.')
            {
                current_pos = std::pair{current_pos.first, current_pos.second + 1};
            }
        }
    }

    // now we go through the grid and add up the counts.
    int total_count = 0;
    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid[0].size(); j++)
        {
            if(grid[i][j] == 'O')
            {
                total_count += (100 * i + j);
            }
        }
    }

    std::cout << "Total count: " << total_count;
}
