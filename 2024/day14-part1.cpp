#include<vector>
#include<string>
#include<algorithm>
#include<iostream>

struct Robot {
    std::pair<int, int> position{};
    std::pair<int, int> velocity{};
    static constexpr int width = 101;
    static constexpr int height = 103;

    Robot(std::pair<int,int> pos, std::pair<int, int> vel)
    {
        position = pos;
        velocity = vel;
    }

    auto get_width(int x)
    {
        if(x >= width)
        {
            return x - width;
        }
        else if(x < 0){
            return width - (0 - x);
        }
        else {
            return x;
        }
    }

    auto get_height(int x)
    {
        if(x >= height)
        {
            return x - height;
        }
        else if(x < 0){
            return height - (0 - x);
        }  
        else {
            return x;
        }
    }

    auto move() -> void {
        int width = get_width(position.first + velocity.first);
        int height = get_height(position.second + velocity.second);
        position = std::pair{width, height};
    }
};

auto my_find(std::string s, char c)
{
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == c)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    std::vector<Robot> robots{};
    std::string line{};
    while(std::getline(std::cin, line) && line != "" && line != "ENDOFLINE")
    {
        int pos_first = 0;
        int pos_second = 0;
        pos_first = std::stoi(line.substr(my_find(line, '=') + 1, my_find(line, ',') - (my_find(line, '=') + 1)));
        pos_second = std::stoi(line.substr(my_find(line, ',') + 1, my_find(line, ' ') - (my_find(line, ',') + 1)));
        
        line = line.substr(my_find(line, 'v') + 2, line.size());

        int vel_first = 0;
        int vel_second = 0;
        vel_first = std::stoi(line.substr(0, my_find(line, ',')));
        vel_second = std::stoi(line.substr(my_find(line, ',') + 1, line.size()));

        robots.push_back(Robot(std::pair{pos_first, pos_second}, std::pair{vel_first, vel_second}));
    }

    // now we need 100 seconds to elapse
    for(int i = 0; i < 100; i++)
    {
        for(auto& x : robots)
        {
            x.move();
        }
    }

    // now we need to put it in an array.
    std::vector<std::vector<int>> grid{103, std::vector<int>(101, 0)};

    // now we need to go through each of the robots and put them in the grid.
    for(auto x : robots)
    {
        grid[x.position.second][x.position.first] = 1;
    }

    int first_quarter = 0;
    int second_quarter = 0;
    int third_quarter = 0;
    int fourth_quarter = 0;
    // now we need to count the number in each quarter.
    // count first quarter.
    for(int i = 0; i < 51; i++)
    {
        for(int j = 0; j < 50; j++)
        {
            if(grid[i][j] == 1)
            {
                first_quarter += 1;
            }
        }
    }

    for(int i = 52; i < 103; i++)
    {
        for(int j = 0; j < 50; j++)
        {
            if(grid[i][j] == 1)
            {
                second_quarter += 1;
            }
        }
    }

    for(int i = 0; i < 51; i++)
    {
        for(int j = 51; j < 101; j++)
        {
            if(grid[i][j] == 1)
            {
                third_quarter += 1;
            }
        }
    }

    for(int i = 52; i < 103; i++)
    {
        for(int j = 51; j < 101; j++)
        {
            if(grid[i][j] == 1)
            {
                third_quarter += 1;
            }
        }
    }

    std::cout << "Safety: " << (first_quarter * second_quarter * third_quarter * fourth_quarter) << "\n";
}
