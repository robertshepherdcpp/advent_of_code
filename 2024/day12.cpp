#include<iostream>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>
#include<string>

auto is_in(std::pair<int, int> p, std::vector<std::vector<std::pair<int, int>>>& grid)
{
    for(auto x : grid)
    {
        if(std::find(x.begin(), x.end(), p) != std::end(x))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    std::vector<std::vector<char>> grid{};

    // first we need to get the input
    std::string line{};
    while(std::getline(std::cin, line) && line != "" && line != "ENDOFLINE")
    {
        std::vector<char> current{};
        for(auto x : line)
        {
            current.push_back(x);
        }
        grid.push_back(current);
    }

    // then we need to seperate the things into alotments
    std::vector<std::vector<std::pair<int, int>>> alotments{};
    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid.size(); j++)
        {
            int current_number = grid[i][j];
            while(!is_in(std::pair{i, j}, alotments))
            {
                // so we have to 
            }
        }
    }
}
