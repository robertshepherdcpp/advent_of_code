#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>

int main()
{
    std::vector<std::vector<char>> grid{};
    std::string line{};
    while(std::getline(std::cin, line))
    {
        std::vector<char> vec{};
        for(auto x : line)
        {
            vec.push_back(x);
        }
        grid.push_back(vec);
    }

    // after we have the grid, we need to find the starting pos.
    std::pair<int, int> start{};
    std::pair<int, int> end{};
    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid[0].size(); j++)
        {
            if(grid[i][j] == 'S')
            {
                start = {i, j};
            }
            else if(grid[i][j] == 'E')
            {
                end = {i, j};
            }
        }
    }
}
