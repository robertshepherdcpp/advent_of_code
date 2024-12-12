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

auto all_options(int value, std::pair<int, int> pos, std::vector<std::vector<char>>& grid)
{
    std::vector<std::pair<int, int>> result{};
    if(pos.first > 0)
    {
        if(grid[pos.first - 1][pos.second] == value)
        {
            result.push_back(std::pair<int, int>{pos.first - 1, pos.second});
        }
    }
    if(pos.first < grid.size() - 1)
    {
        if(grid[pos.first + 1][pos.second] == value)
        {
            result.push_back(std::pair<int, int>{pos.first + 1, pos.second});
        }
    }
    if(pos.first > 0)
    {
        if(grid[pos.first][pos.second - 1] == value)
        {
            result.push_back(std::pair<int, int>{pos.first, pos.second - 1});
        }
    }
    if(pos.first < grid[0].size() - 1)
    {
        if(grid[pos.first][pos.second + 1] == value)
        {
            result.push_back(std::pair<int, int>{pos.first, pos.second + 1});
        }
    }
    return result;
}

auto all_options(int value, std::pair<int, int> pos, std::vector<std::vector<int>>& grid)
{
    int count = 0;
    if(pos.first > 0)
    {
        if(grid[pos.first - 1][pos.second] == value)
        {
            count += 1;
        }
    }
    if(pos.first < grid.size() - 1)
    {
        if(grid[pos.first + 1][pos.second] == value)
        {
            count += 1;
        }
    }
    if(pos.first > 0)
    {
        if(grid[pos.first][pos.second - 1] == value)
        {
            count += 1;
        }
    }
    if(pos.first < grid[0].size() - 1)
    {
        if(grid[pos.first][pos.second + 1] == value)
        {
            count += 1;
        }
    }
    return count; 
}

template<typename T>
auto my_find(std::vector<T>& vec, T value)
{
    for(int i = 0; i < vec.size(); i++)
    {
        if(vec[i] == value)
        {
            return i;
        }
    }
    return -1;
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
    
    std::cout << "finished input\n";

    // then we need to seperate the things into alotments
    std::vector<std::vector<std::pair<int, int>>> alotments{};
    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid.size(); j++)
        {
            int current_number = grid[i][j];
            std::pair<int, int> current = std::pair{i, j};
            bool all_explored = false;
            std::vector<std::pair<int, int>> explored{};
            std::vector<std::pair<int, int>> options{};
            while(!all_explored)
            {
                // so we have to get all the ones in this alotment
                explored.push_back(current);
                auto availables = all_options(current_number, current, grid);
                if(availables.size() > 1)
                {
                    options.push_back(current);
                }
                auto prev_current = current;
                for(auto x : availables)
                {
                    if(my_find(explored, x) == -1)
                    {
                        // if its not found then we look at it
                        current = x;
                    }
                }
                if(current == prev_current)
                {
                    // this means we havent found one we go back to the last one that had multiple
                    // different points
                    auto point = options[options.size() - 1];
                    auto now_available = all_options(current_number, current, grid);
                    if(now_available.size() == 0)
                    {
                        options.pop_back();
                        if(options.size() == 0)
                        {
                            all_explored = true;
                        }
                    }
                    else if(now_available.size() == 1){
                        if(my_find(explored, current) == -1)
                        {
                            current = now_available[0];
                        }
                        options.pop_back();
                        if(options.size() == 0)
                        {
                            all_explored = true;
                        }
                    }
                    else {
                        for(int i = 0; i < options.size(); i++)
                        {
                            if(my_find(explored, options[i]) == -1)
                            {
                                // if its not found then we look at it
                                current = options[i];
                            }
                        }
                    }
                }
            }
            // then after we can sort the array
            auto lambda_predicate = [](std::pair<int, int> a, std::pair<int, int> b)
            {
                return a.first < b.first;
            };
            std::sort(explored.begin(), explored.end(), lambda_predicate);
            alotments.push_back(explored);
        }
    }

    // now we need to remove duplicates
    std::sort(alotments.begin(), alotments.end());
    alotments.erase(std::unique(alotments.begin(), alotments.end()), alotments.end());

    // now that we have our individual alotments, we need find the prices of the fences for them.
    // so we know the area
    int total_cost = 0;
    for(auto x : alotments)
    {
        int cost = alotments.size(); // we already know this.
        // now we need to put this all in a grid.
        std::vector<std::vector<int>> binary_grid{};
        for(int i = 0; i < grid.size(); i++)
        {
            std::vector<int> current_vector{};
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(my_find(x, std::pair{i, j}) == -1)
                {
                    current_vector.push_back(0);
                }
                else {
                    current_vector.push_back(1);
                }
            }
            binary_grid.push_back(current_vector);
        }
        // after weve got the binary grid, we need to get perimeter.
        int perimeter = 0;
        for(int i = 0; i < binary_grid.size(); i++)
        {
            for(int j = 0; j < binary_grid[0].size(); j++)
            {
                if(all_options(1, std::pair{i, j}, binary_grid) == 1)
                {
                    perimeter += 3;
                }
                else if(all_options(1, std::pair{i, j}, binary_grid) == 2)
                {
                    perimeter += 2;
                }
                else if(all_options(1, std::pair{i, j}, binary_grid) == 3)
                {
                    perimeter += 1;
                }
                else {
                    // we do nothing as it doesnt have a permimeter
                }
            }
        }
        cost *= perimeter;
        total_cost += cost;
    }
    std::cout << "Total cost: " << total_cost << "\n";
}
