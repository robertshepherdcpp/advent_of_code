// didnt actually finish needs finishing:
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>

int main()
{
    std::string line{};
    std::vector<std::vector<int>> reports{};
    while(std::getline(std::cin, line) and line != "EXIT")
    {
        std::vector<int> current_report{0, int(line.size()) / 2};
        std::string current{};
        for(auto& x : line)
        {
            if(x != ' ')
            {
                current += std::string{x};
            }
            else {
                current_report.push_back(std::stoi(current));
                current = {};
            }
        }
        reports.push_back(current_report);
    }

    // after weve got our input we need to go through each vector in reports 1 by 1
    int valid_count = 0;
    for(auto& x : reports)
    {
        bool isValid = true;
        // first we need to check whether the value is always incrementing or decrementing.
        bool isIncreasing = (x[0] - x[1]) < 0;
        for(int i = 0; i < x.size() - 1; i++)
        {
            if(isIncreasing && !((x[i] - x[i + 1]) < 0))
            {
                // this one isnt a valid entry.
                isValid = false;
                break;
            }
            else if(!isIncreasing && (x[i] - x[i - 1]) < 0) {
                // this isnt valid either.
                isValid = false;
                break;
            }
        }
        // now we need to transform the vector into its differences between the 2 closest values.
        if(isValid)
        {
            std::vector<int> differences{};
            std::adjacent_difference(x.begin(), x.end(), differences.begin());
            isValid = std::count_if(differences.begin(), differences.end(), [](int a){return a == 0 or a > 3 or a < -3;}) == 0;
        }
        if(isValid)
        {
            valid_count += 1;
        }
    }
    std::cout << valid_count << '\n';
}
