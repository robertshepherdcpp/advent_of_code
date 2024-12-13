#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<utility>

auto my_find(std::string line, char c)
{
    for(int i = 0; i < line.size(); i++)
    {
        if(line[i] == c)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    std::vector<std::vector<std::pair<int, int>>> machines{};
    std::vector<std::pair<int, int>> current_vector{};
    std::string line{};
    while(std::getline(std::cin, line) && line != "ENDOFLINE")
    {
        if(line == "")
        {
            // this means that we need a new machine
            machines.push_back(current_vector);
            current_vector = {};
        }
        else if(line.substr(0, 8) == "Button A")
        {
            int first_number = 0;
            int second_number = 0;
            first_number = std::stoi(line.substr(12, my_find(line, ',') - 12));
            second_number = std::stoi(line.substr(my_find(line, ',') + 4, line.size()));
            current_vector.push_back(std::pair{first_number, second_number});
        }
        else if(line.substr(0, 8) == "Button B")
        {
            int first_number = 0;
            int second_number = 0;
            first_number = std::stoi(line.substr(12, my_find(line, ',') - 12));
            second_number = std::stoi(line.substr(my_find(line, ',') + 4, line.size()));
            current_vector.push_back(std::pair{first_number, second_number});
        }
        else if(line.substr(0, 5) == "Prize")
        {
            int first_number = 0;
            int second_number = 0;
            first_number = std::stoi(line.substr(9, my_find(line, ',') - 9));
            second_number = std::stoi(line.substr(my_find(line, ',') + 4, line.size()));
            current_vector.push_back(std::pair{first_number, second_number});
        }
    }

    // after weve got out input, we need to find a combination that will add up to the desired number.
    // all possible combinations.
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
        {
        }
    }
}
