#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

auto index_find(std::string s, char c)
{
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == c)
        {
            return i;
        }
    }
    return -1;
}

auto times(char c, int count)
{
    return std::string(count, c);
}

int main()
{
    std::string line_{};
    std::string line{};
    while(std::getline(std::cin, line_) && line_ != "ENDOFLINE" && line_ != "")
    {
        line += line_;
    }

    std::string finished{};

    // first we need to parse the string.
    // line = "2333133121414131402";
    int current_index = 0;
    std::string parsed{};
    for(int i = 0; i < line.size(); i++)
    {
        // std::cout << "pase loop";
        if(i % 2 == 0)
        {
            // this means it is the lenth of the file.
            parsed += times(char(current_index) + 48, int(line[i]) - 48);
            current_index += 1;
        }
        else {
            parsed += times('.', int(line[i]) - 48);
        }
    }

    line = parsed;

    // std::cout << line << "\n";

    // after weve put it in the speific form we need to, rearrange
    for(int i = line.size() - 1; i > 0; i--)
    {
        if(line[i] != '.')
        {
            // we need to find the first free space starting from the front
            if(index_find(line, '.') > i && finished == "")
            {
                // if its greater than i, that means weve finished.
                finished = line;
            }
            else if(index_find(line, '.') < i)
            {
                // we need to swap the indexes.
                char copy = line[index_find(line, '.')];
                line[index_find(line, '.')] = line[i];
                line[i] = copy;
            }
        }
    }

    // now we need to get a total count
    int index = line.find('.');
    int total_count = 0;
    for(int i = 0; i < index; i++)
    {
        //std::cout << i << " * " << line[i] << " = " << i * (int(line[i]) - 48) << " | count: " << total_count << "\n";
        total_count +=  i * (int(line[i]) - 48);
    }

    //std::cout << line << "\n";
    std::cout << "total count: " << total_count << "\n\n\n";
}
