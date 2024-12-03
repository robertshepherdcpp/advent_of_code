#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<exception>

int main()
{
    // first get input, well do it line by line,
    int total_count = 0;
    std::string line{};
    while(std::getline(std::cin, line) and line != "ENDOFLINE")
    {
        std::string shortened{line};
        while(shortened.find("mul(") != -1)
        {
            int index = shortened.find("mul");
            std::string temp = shortened.substr(index, shortened.size());

            // first number
            int first_number_index = temp.find(",") + index;
            std::string first_number = shortened.substr(index, first_number_index);

            // second number
            int second_number_index = first_number_index + 1;
            int bracket_index = temp.find(")");
            std::string second_number = shortened.substr(second_number_index, bracket_index);

            shortened = shortened.substr(index + 4, shortened.size());
            int first_number_val = 0;
            int second_number_val = 0;
            bool are_valid = true;
            try {
                first_number_val = std::stoi(first_number);
                second_number_val = std::stoi(second_number);
            } catch(std::exception x)
            {
                are_valid = false;
            }
            if(are_valid)
            {
                total_count += (first_number_val * second_number_val);
            }
        }
    }
    std::cout << total_count;
}
