#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<ranges>
#include<map>

int main()
{
    std::vector<std::vector<char>> grid{};

    std::string line{};
    while(std::getline(std::cin, line) && line != "\n" && line != "END" && line != " " && line != "")
    {
        //std::cout << "on first line\n";
        std::vector<char> current_vec{};
        for(auto i : line)
        {
            current_vec.push_back(i);
        }
        grid.push_back(current_vec);
        
    }
    
    //std::cout << "finished input\n";

    // now that weve got input, we need to find the position of the person.
    // first int is the y, second int is the x
    std::pair<int, int> position{};
    for(int x=0; x < grid.size(); x++) {
        if(std::ranges::find(grid[x], '^') != std::ranges::end(grid[x]))
        {
            for(int i = 0; i < grid[x].size(); i++)
            {
                if(grid[x][i] == '^')
                {
                    position.first = x;
                    position.second = i;
                }
            }
        }
    }
    
    //std::cout << "Position, first: " << position.first << ", second: " << position.second << '\n';

    // after weve got the position, we need to make actually do the security guard movement.
    std::map<std::pair<int, int>, int> positions_visited{}; // to count unique values.
    std::pair<int, int> current_position{position};
    char direction = 'N';
    std::map<char, std::pair<int, int>> moves {
        {'N', std::pair<int, int>{-1, 0}},
        {'E', std::pair<int, int>{0, 1}},
        {'S', std::pair<int, int>{1, 0}},
        {'W', std::pair<int, int>{0, -1}}
    };
    std::vector<char> compass_points{'N', 'E', 'S', 'W'};
    bool carry_on = true;
    while(current_position.first >= 0 && current_position.first <= grid.size() - 1 && current_position.second >= 0 && current_position.second <= grid[0].size() - 1 && carry_on)
    {
        positions_visited[current_position] = 1;
        if(grid[current_position.first + moves[direction].first][current_position.second + moves[direction].second] == '#')
        {
            // we then need to rotate 90 degrees
            if(direction == 'N')
            {
                direction = 'E';
            }
            else if(direction == 'E')
            {
                direction = 'S';
            }
            else if(direction == 'S')
            {
                direction = 'W';
            }
            else if(direction == 'W')
            {
                direction = 'N';
            }
            // now that it is rotated 90 degrees, we move forwards/backwards/left/right depending on direction variable.
        }
        current_position.first += moves[direction].first;
        current_position.second += moves[direction].second;
        
        //std::cout << "updated position, first: " << current_position.first << " second: " << current_position.second << "\n";
        if(current_position.first == grid.size() - 1 || current_position.second == grid[0].size() - 1)
        {
            positions_visited[current_position] = 1;
            carry_on = false;
        }
    }

    // after finished, we accumulate the values, these will be the unique values.
    int count = 0;
    for(auto [key, value] : positions_visited)
    {
        count += 1;
    }
    std::cout << count << "\n";
}
