#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<ranges>
#include<algorithm>

auto split(std::string line, char delimeter)
{
    std::vector<std::string> result{};
    // int current_index = 0;
    std::string temp_string = line;
    while(temp_string.size() > 0)
    {
        if(temp_string.find(delimeter) != -1)
        {
            result.push_back(temp_string.substr(0, temp_string.find(delimeter)));
            std::string new_str = temp_string.substr(temp_string.find(delimeter) + 1, temp_string.size());
            temp_string = new_str;
        }
        else {
            result.push_back(temp_string);
            temp_string = "";
        }
    }

    return result;
}

auto blink(std::vector<std::string>& strings)
{
    std::vector<std::string> result{};
    for(auto x : strings)
    {
        if(x == "0")
        {
            result.push_back("1");
        }
        else if(x.size() % 2 == 0)
        {
            long long first_integer = std::stoll(x.substr(0, x.size() / 2));
            long long second_integer = std::stoll(x.substr(x.size() / 2, x.size()));
            result.push_back(std::to_string(first_integer));
            result.push_back(std::to_string(second_integer));
        }
        else {
            long long integer = std::stoll(x);
            integer *= 2024;
            result.push_back(std::to_string(integer));
        }
    }
    return result;
}

int main()
{
    //std::string test = "510613 358 84 40702 4373582 2 0 1584";
    std::string line{};
    std::string line_{};
    line = "510613 358 84 40702 4373582 2 0 1584";
    // while(std::getline(std::cin, line_) && line_ != "ENDOFLINE" && line_ != "")
    // {
    //     line = line_;
    // }

    // split up into individual strings.
    std::vector<std::string> strings = split(line, ' ');

    // now that weve got the line we need to blink 25 times
    for(int i = 0; i < 25; i++)
    {
        strings = blink(strings);
    }
    std::cout << "string size: " << strings.size();
}
