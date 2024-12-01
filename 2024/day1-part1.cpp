#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

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

    // now we need to sort the array

    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());

    // after sorting we need to add up distances
    int diff = 0;
    for(int i = 0; i < nums1.size(); i++)
    {
        diff += std::max(nums1[i], nums2[i]) - std::min(nums1[i], nums2[i]);
    }

    std::cout << diff;
}
