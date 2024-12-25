#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include<map>

auto fits(std::vector<std::vector<char>>& a, std::vector<std::vector<char>>& b)
{
    for(int i = 0; i < a.size(); i++)
    {
        for(int j = 0; j < a.size(); j++)
        {
            if(a[i][j] == '#' && b[i][j] == '#')
            {
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::vector<std::vector<std::vector<char>>> keys{};
    std::vector<std::vector<char>> current_key{};
    std::string line{};
    while (std::getline(std::cin, line) && line != "ENDOFLINE") {
        if (line == "") {
            keys.push_back(current_key);
        } else {
            std::vector<char> curr{};
            for (auto x : line) {
                curr.push_back(x);
            }
            current_key.push_back(curr);
        }
    }

    // after we have the input, we need to find all possible combinations.
    std::map<std::vector<std::vector<char>>, int> used{};
    for(int i = 0; i < keys.size(); i++)
    {
        for(int j = 0; j < keys.size(); j++)
        {
            // so now we have 2 keys, we need to check if they fit.
            if(fits(keys[i], keys[j]) && !used.contains(keys[i]) && !used.contains(keys[j]))
            {
                used[keys[i]] = 1;
                used[keys[j]] = 1;
            }
        }
    }

    // now that we have the map of unique pairs, count them
    int count = used.size();
    
    std::cout << count << "\n";

    return used.size();
}
