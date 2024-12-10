#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>

auto get_possible_moves(std::vector<std::vector<char>>& vec,
                        int current_number,
                        std::pair<int, int>& current_position)
                        -> std::vector<std::pair<int, int>>
{
    std::vector<std::pair<int, int>> result{};

    if(current_position.first + 1 < vec.size() &&
       vec[current_position.first + 1][current_position.second] == current_number + 1)
    {
        result.push_back(std::pair<int, int>{current_position.first + 1, current_position.second});
    }
    if(current_position.first - 1 >= 0 &&
       vec[current_position.first - 1][current_position.second] == current_number + 1)
    {
        result.push_back(std::pair<int, int>{current_position.first - 1, current_position.second});
    }
    if(current_position.second + 1 < vec[0].size() &&
       vec[current_position.first][current_position.second + 1] == current_number + 1)
    {
        result.push_back(std::pair<int, int>{current_position.first, current_position.second + 1});
    }
    if(current_position.second - 1 >= 0 &&
       vec[current_position.first][current_position.second - 1] == current_number + 1)
    {
        result.push_back(std::pair<int, int>{current_position.first, current_position.second - 1});
    }

    return result;
}

int main()
{
    std::vector<std::vector<char>> strings{};
    std::string line{};

    while(std::getline(std::cin, line) && line != "ENDOFLINE" && line != "")
    {
        std::vector<char> res{};
        for(auto x : line)
        {
            res.push_back(x);
        }
        strings.push_back(res);
    }

    // now we need to find the positions of the "trailhead"
    std::vector<std::pair<int, int>> trailhead_positions{};
    for(int i = 0; i < strings.size(); i++)
    {
        for(int j = 0; j < strings[0].size(); j++)
        {
            if(strings[i][j] == '0')
            {
                trailhead_positions.push_back(std::pair<int, int>{i, j});
            }
        }
    }

    // after weve got the trailhead positions we need to do an exploring algorithm
    // first store all the turning_point positions
    std::vector<std::pair<int, int>> turning_points{};
    int turning_point_count = 0;
    for(int i = 0; i < trailhead_positions.size(); i++)
    {
        int current_num = 0;
        std::pair<int, int> current_position = trailhead_positions[i];
        while(current_num != 9)
        {
            auto arr = get_possible_moves(strings, current_num, trailhead_positions[i]);
            if(arr.size() > 1)
            {
                turning_points.push_back(trailhead_positions[i]);
            }
            turning_point_count += arr.size();
            current_position = arr[0];
            current_num += 1;
        }
    }

    // after weve got all the 
}
