#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<utility>
#include<cmath>

auto split_string(std::string s) -> std::vector<std::string>
{
    std::vector<std::string> result{};
    int last_index = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(i == ' ')
        {
            result.push_back(s.substr(last_index, i - last_index));
            last_index = i + 1;
        }
    }
    return result;
}

auto number_of(int n, char c)
{
    std::string result{};
    for(int i = 0; i < n; i++)
    {
        result += std::string{c};
    }
    return result;
}

auto integer_to_binary(int n, int length) -> std::string
{
    std::string binary{};
    while(n > 0)
    {
        binary = (n % 2 == 0 ? "0" : "1") + binary;
        n /= 2;
    }
    return binary;
    if(binary.size() < length)
    {
        binary = number_of(length - binary.size(), '0') + binary;
    }
}

int maximum_number(int size)
{
    return std::pow(2, size) - 1;
}

auto to_sign(char c) -> std::string
{
    return (c == '0' ? std::string{"+"} : std::string{"*"});
}

int main()
{
    std::vector<std::pair<int, std::vector<int>>> vec{};

    int overall_total = 0;

    std::string line{};
    while(std::getline(std::cin, line) && line != "ENDOFLINE" && line != "")
    {
        std::string test_value = line.substr(0, line.find(":"));
        int test_value_val = std::stoi(test_value);

        std::vector<std::string> operands = split_string(line.substr(line.find(":") + 2, line.size()));
        // now turn these strings into integers
        std::vector<int> operands_ints{};
        for(auto x : operands)
        {
            operands_ints.push_back(std::stoi(x));
        }

        // after weve got the ints, we need to find a way of getting every possible combination.
        // we could do it like binary, where 1 is +, 0 is *, the number of bits is equal to the length of the
        // vector operands_ints - 1 (because the signs are between the numbers)

        // we start of with
        int maximum_number_val = maximum_number(operands_ints.size() - 1);
        for(int i = 0; i < maximum_number_val; i++)
        {
            std::string str = integer_to_binary(i, operands_ints.size() - 1);
            // now convert this into pluses and minuses
            std::vector<std::string> expression{};
            int v = 0;
            for(int j = 0; j < operands.size(); j++)
            {
                expression.push_back(operands[j]);
                if(v < str.size())
                {
                    expression.push_back(to_sign(str[v]));
                }
                v++;
            }

            // now that weve got the expression we need to execute it.
            int total_count = 0;
            for(int j = 0; j < expression.size(); j++)
            {
                if(expression[j] == "+")
                {
                    total_count += std::stoi(expression[j + 1]);
                    j += 1;
                }
                else if(expression[j] == "*")
                {
                    total_count *= std::stoi(expression[j + 1]);
                    j += 1;
                }
                else {
                    // its a number.
                    total_count = std::stoi(expression[j]);
                }
            }
            if(total_count == test_value_val)
            {
                overall_total += total_count;
            }
        }
    }
    std::cout << overall_total;
}
