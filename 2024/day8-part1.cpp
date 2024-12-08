#include<string>
#include<vector>
#include<iostream>
#include<utility>
#include<algorithm>
#include<map>

auto find_diff(std::pair<int, int> first_, std::pair<int, int> second_) -> std::pair<int, int>
{
    return std::pair<int, int>{first_.first - second_.first,
                               first_.second - second_.second};
}

auto invert(std::pair<int, int> diff) -> std::pair<int, int>
{
    return std::pair<int, int>{diff.first * -1, diff.second * -1};
}

int main()
{
    std::map<std::pair<int, int>, int> unique_positions{};
    std::vector<std::vector<char>> grid{};

    std::string line{};
    while(std::getline(std::cin, line) && line != "ENDOFLINE" && line != "")
    {
        std::vector<char> temp{};
        for(auto x : line)
        {
            temp.push_back(x);
        }
        grid.push_back(temp);
    }

    // now weve got our grid, we need to find all the different characters there are.
    std::map<char, int> unique_characters{};
    for(auto x : grid)
    {
        for(auto y : x)
        {
            if(y != '.')
            {
                std::cout << "unique character: " << y << "\n";
                unique_characters[y] = 0;
            }
        }
    }

    // now we go through the map, and get all of the characters.
    std::vector<char> unique_chars_vec{};
    for(auto [key, value] : unique_characters)
    {
        unique_chars_vec.push_back(key);
    }

    // now that weve got our unique characters, we need to look at all of the characters, comparing 2 at a time.
    // first make a bit array of std::pair with all the posiitons of the characters.
    std::vector<std::pair<int, int>> positions{};
    for(auto character : unique_chars_vec)
    {
        // find all positions of character.
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == character)
                {
                    positions.push_back(std::pair{i, j});
                }
            }
        }

        // now weve got all the positions we need to compare 2 at a time
        for(int i = 0; i < positions.size() - 1; i++)
        {
            int j = i + 1;
            std::pair<int, int> diff = find_diff(positions[i], positions[j]);
            if((positions[j].first + diff.first) >= 0 && (positions[j].first + diff.first) < grid.size() && 
               (positions[j].second + diff.second) >= 0 && (positions[j].second + diff.second) < grid[0].size())
            {

                unique_positions[std::pair<int, int>{positions[j].first - diff.first, positions[j].second - diff.second}] = 0;
                auto x = std::pair<int, int>{positions[i].first - diff.first, positions[i].second - diff.second};
                std::cout << "added pair: " << x.first << ", " << x.second << "\n";
                
            }
            diff = invert(diff);
            if((positions[i].first + diff.first) >= 0 && (positions[i].first + diff.first) < grid.size() && 
               (positions[i].second + diff.second) >= 0 && (positions[i].second + diff.second) < grid[0].size())
            {
                unique_positions[std::pair<int, int>{positions[i].first - diff.first, positions[i].second - diff.second}] = 0;
                auto x = std::pair<int, int>{positions[i].first - diff.first, positions[i].second - diff.second};
                std::cout << "added pair: " << x.first << ", " << x.second << "\n";
                
            }
        }
    }
    int count = 0;
    for(auto [key, value] : unique_positions)
    {
        count += 1;
    }
    std::cout << count << "\n";
}
