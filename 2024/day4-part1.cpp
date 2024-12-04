#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

auto vector_sub_array(std::vector<char>& arr, int start, int end) {
    std::vector<char> result{};
    for (int i = start; i < end; i++) {
        result.push_back(arr[i]);
    }
    return result;
}

int main() {
    int total_count = 0;
    std::vector<char> xmas_char_vec = std::vector<char>{'X', 'M', 'A', 'S'};
    std::vector<char> reverse_xmas_char_vec{};
    {
        auto copy = xmas_char_vec;
        std::reverse(copy.begin(), copy.end());
        reverse_xmas_char_vec = copy;
    }

    std::vector<std::vector<char>> grid{};
    std::string line{};
    while (std::getline(std::cin, line) && line != "ENDOFLINE") {
        std::vector<char> grid_line{};
        for (auto x : line) {
            grid_line.push_back(x);
        }
        grid.push_back(grid_line);
    }

    // after we have the array first look for xmas in normal order.
    for (int i = 0; i < grid.size(); i++) {
        // so now look for substr of a vector to be equal to a the vector xmas
        for (int j = 0; j < grid[i].size() - 4; j++) {
            if (vector_sub_array(grid[i], j, 4) == xmas_char_vec ||
                vector_sub_array(grid[i], j, 4) == reverse_xmas_char_vec) {
                total_count += 1;
            }
        }
    }

    // now we need to look for the case of diagonals, (looking for forwards
    // diagonals)
    auto current_longest = std::vector<char>{};
    for (int i = 0; i < grid.size(); i++) {
        int j = i + 1;
        if (j < grid[0].size()) {
            if (grid[i][j] == xmas_char_vec[current_longest.size()]) {
                current_longest.push_back(grid[i][j]);
                if (current_longest == xmas_char_vec) {
                    total_count += 1;
                    current_longest = {};
                }
            } else {
                current_longest = {};
            }
        }
    }
    current_longest = {};

    // now we need to look for the case the diagonal going forwards with
    // reversed XMAS (SAMX)
    for (int i = 0; i < grid.size(); i++) {
        int j = i + 1;
        if (j < grid[0].size()) {
            if (grid[i][j] == reverse_xmas_char_vec[current_longest.size()]) {
                current_longest.push_back(grid[i][j]);
                if (current_longest == reverse_xmas_char_vec) {
                    total_count += 1;
                    current_longest = {};
                }
            } else {
                current_longest = {};
            }
        }
    }
    current_longest = {};

    // we now need to look for the case where the diagonal goes backwards with XMAS
    for (int i = grid.size() - 1; i > 0; i--) {
        int j = i - 1;
        if (j >= 0) {
            if (grid[i][j] == xmas_char_vec[current_longest.size()]) {
                current_longest.push_back(grid[i][j]);
                if (current_longest == xmas_char_vec) {
                    total_count += 1;
                    current_longest = {};
                }
            } else {
                current_longest = {};
            }
        }
    }
    current_longest = {};

    // now we need to look for the case where the diagonals go backwards with SAMX
    for (int i = grid.size() - 1; i > 0; i--) {
        int j = i - 1;
        if (j >= 0) {
            if (grid[i][j] == reverse_xmas_char_vec[current_longest.size()]) {
                current_longest.push_back(grid[i][j]);
                if (current_longest == reverse_xmas_char_vec) {
                    total_count += 1;
                    current_longest = {};
                }
            } else {
                current_longest = {};
            }
        }
    }
    current_longest = {};

    // now we need to check for going downwards.
    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == xmas_char_vec[current_longest.size()]) {
                current_longest.push_back(grid[i][j]);
                if (current_longest == xmas_char_vec) {
                    total_count += 1;
                    current_longest = {};
                }
            } else {
                current_longest = {};
            } 
        }
    }

    // now we need to check for going downwards with SAMX:
    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == reverse_xmas_char_vec[current_longest.size()]) {
                current_longest.push_back(grid[i][j]);
                if (current_longest == reverse_xmas_char_vec) {
                    total_count += 1;
                    current_longest = {};
                }
            } else {
                current_longest = {};
            } 
        }
    }
    std::cout << total_count << "\n";
}
