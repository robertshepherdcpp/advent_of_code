#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

auto my_find(std::string line, char c) {
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == c) {
            return i;
        }
    }
    return -1;
}

auto number_of(int n, char c) {
    std::string result{};
    for (int i = 0; i < n; i++) {
        result += std::string{c};
    }
    return result;
}

int maximum_number(int size) { return std::pow(2, size) - 1; }

auto integer_to_binary(int n, int length) -> std::string {
    std::string binary{};
    while (n > 0) {
        binary = (n % 2 == 0 ? "0" : "1") + binary;
        n /= 2;
    }
    if (binary.size() < length) {
        binary = number_of(length - binary.size(), '0') + binary;
    }
    return binary;
}

int main() {
    std::vector<std::vector<std::pair<int, int>>> machines{};
    std::vector<std::pair<int, int>> current_vector{};
    std::string line{};
    while (std::getline(std::cin, line) && line != "ENDOFLINE") {
        if (line == "") {
            // this means that we need a new machine
            machines.push_back(current_vector);
            current_vector = {};
        } else if (line.substr(0, 8) == "Button A") {
            int first_number = 0;
            int second_number = 0;
            first_number = std::stoi(line.substr(12, my_find(line, ',') - 12));
            second_number =
                std::stoi(line.substr(my_find(line, ',') + 4, line.size()));
            current_vector.push_back(std::pair{first_number, second_number});
        } else if (line.substr(0, 8) == "Button B") {
            int first_number = 0;
            int second_number = 0;
            first_number = std::stoi(line.substr(12, my_find(line, ',') - 12));
            second_number =
                std::stoi(line.substr(my_find(line, ',') + 4, line.size()));
            current_vector.push_back(std::pair{first_number, second_number});
        } else if (line.substr(0, 5) == "Prize") {
            int first_number = 0;
            int second_number = 0;
            first_number = std::stoi(line.substr(9, my_find(line, ',') - 9));
            second_number =
                std::stoi(line.substr(my_find(line, ',') + 4, line.size()));
            current_vector.push_back(std::pair{first_number, second_number});
        }
    }

    // after weve got out input, we need to find a combination that will add up
    // to the desired number. all possible combinations. could use binary
    int overall_cost = 0;
    for (auto x : machines) {
        std::vector<int> working_values{}; // will hold all the cost values
        for (int i = 0; i < maximum_number(100); i++) {
            std::string str = integer_to_binary(i, 100);
            std::pair<int, int> start{};
            int cost = 0;
            for (char c : str) {
                if (c == '0') {
                    // 0 will be button A.
                    start.first += x[0].first;
                    start.second += x[0].second;
                    cost += 3;
                }
                else if(c == '1')
                {
                    start.second += x[1].first;
                    start.second += x[1].first;
                    cost += 1;
                }
            }
            // after weve gone through each charcter, we need to see if the start (updated start)
            // is equal to the x[2]
            if(start == x[2])
            {
                // this means that this combination worked.
                working_values.push_back(cost);
            }
        }
        // now we need to find the overall cost.
        if(working_values.size() == 0)
        {
            // this means no possible solutions where found for this specific one
        }
        else {
            overall_cost += *std::min_element(working_values.begin(), working_values.end());
        }
    }

    std::cout << "Overall cost: " << overall_cost;
}
