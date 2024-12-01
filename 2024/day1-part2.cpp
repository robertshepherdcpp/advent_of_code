#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>

int main()
{
    // get input in.
    std::vector<int> nums1 = {};
    std::vector<int> nums2 = {};

    std::string line{};
    while(std::getline(std::cin, line) and line != "-1") {
        bool number_1 = true;
        std::string number_1_str{};
        std::string number_2_str{};
        for(auto& x : line)
        {
            if(int(x) >= 48 and int(x) <= 57)
            {
                if(number_1)
                {
                    number_1_str += std::string{x};
                }
                else if(!number_1)
                {
                    number_2_str += std::string{x};
                }
            }
            else if(x == ' ')
            {
                number_1 = false;
            }
        }

        nums1.push_back(std::stoi(number_1_str));
        nums2.push_back(std::stoi(number_2_str));
    }
    
    std::cout << "finished input\n";

    int similarity_score = 0;
    // create a map with all the values and their occurances in nums2
    std::map<int, int> occurances{};
    for(auto i : nums2)
    {
        occurances[i] = std::count(nums2.begin(), nums2.end(), i);
    }

    // now we need to go through each element in nums1 and times it by the occurances in nums2
    for(auto i : nums1)
    {
        if(occurances.find(i) != std::end(occurances))
        {
            similarity_score += i * occurances[i];
        }
    }

    std::cout << similarity_score;
}
