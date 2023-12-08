#include<iostream>
#include<string>
#include<utility>
#include<vector>
#include<iomanip>

struct key_double_value
{
    auto lookup_value(std::string s) -> std::pair<std::string, std::string>
    {
        for (int i = 0; i < key_values.size(); i++)
        {
            if (key_values[i][0] == s)
            {
                std::pair<std::string, std::string> p = std::pair{ key_values[i][1], key_values[i][2] };
                return p;
            }
        }
    }

    auto convert_lr_one_two(std::string x)
    {
        std::string result{};
        for (const auto y : x)
        {
            if (y == 'l')
            {
                result += "0";
            }
            else
            {
                result += "1";
            }
        }
        std::cout << result << "\n";
        return result;
    }

    auto find_min_amount_of_moves(std::string commands)
    {
        int number_of_moves = 0;
        int count = 0;
        std::string current_value{};
        int current_key{ 0 };
        std::string list = convert_lr_one_two(commands);
        while (current_value != "ZZZ")
        {
            number_of_moves += 1;
            int int_value = list[count] - '0';
            current_value = key_values[current_key][int_value];
            for (int i = 0; i < key_values.size(); i++)
            {
                if (key_values[i][0] == current_value)
                {
                    current_key = i;
                }
            }
            if (count == list.size())
            {
                count = 0;
            }
            else
            {
                count += 1;
            }
            std::cout << current_value << "\n";
        }
        return number_of_moves;
    }

    std::vector<std::vector<std::string>> key_values
    {
        std::vector<std::string>{"AAA", "BBB", "BBB"},
        std::vector<std::string>{"BBB", "AAA", "ZZZ"},
        std::vector<std::string>{"ZZZ", "ZZZ", "ZZZ"}
    };
};

int main()
{
    // this should print 2 as it is only a right move then another right move.
    std::cout << key_double_value{}.find_min_amount_of_moves("RR") << "\n";
}