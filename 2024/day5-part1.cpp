#include<iostream>
#include<string>
#include<vector>

int main()
{
    std::vector<std::vector<int>> correct_orders{};

    // get middle values.
    int total_count = 0;
    for(const auto& v : correct_orders)
    {
        total_count += v[(v.size() + 1) / 2];
    }
}
