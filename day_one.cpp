/*
Something is wrong with global snow production, and you've been selected to take a look. The Elves have even given you a map; on it, they've used stars to mark the top fifty locations that are likely to be having problems.

You've been doing this long enough to know that to restore snow operations, you need to check all fifty stars by December 25th.

Collect stars by solving puzzles. Two puzzles will be made available on each day in the Advent calendar; the second puzzle is unlocked when you complete the first. Each puzzle grants one star. Good luck!

You try to ask why they can't just use a weather machine ("not powerful enough") and where they're even sending you ("the sky") and why your map looks mostly blank ("you sure ask a lot of questions") and hang on did you just say the sky ("of course, where do you think snow comes from") when you realize that the Elves are already loading you into a trebuchet ("please hold still, we need to strap you in").

As they're making the final adjustments, they discover that their calibration document (your puzzle input) has been amended by a very young Elf who was apparently just excited to show off her art skills. Consequently, the Elves are having trouble reading the values on the document.

The newly-improved calibration document consists of lines of text; each line originally contained a specific calibration value that the Elves now need to recover. On each line, the calibration value can be found by combining the first digit and the last digit (in that order) to form a single two-digit number.

For example:

1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet
In this example, the calibration values of these four lines are 12, 38, 15, and 77. Adding these together produces 142.

Consider your entire calibration document. What is the sum of all of the calibration values?
*/

// just look for the last index a character '0' to '9' and then look to see if there is a work spelt like that.
// also do this same type of method for the start

#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<fstream>

auto first_and_last(std::string s) -> std::string
{
	std::string result = std::string{ s[0] } + std::string{ s[s.size() - 1] };
	return result;
}

auto is_number(char c) -> bool
{
	std::vector<char> numbers{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	for (const auto x : numbers)
	{
		if (x == c)
		{
			return true;
		}
	}
	return false;
}

auto remove_letters(std::string& artwork) -> std::string
{
	std::string my_string{};
	for (const auto c : artwork)
	{
		if (is_number(c))
		{
			my_string += std::string{ c };
		}
	}
	return my_string;
}

auto day_one(std::vector<std::string> document) -> int
{
	std::vector<std::string> my_document{ document };
	int total{};
	for (auto& x : my_document)
	{
		total += std::stoi(first_and_last(remove_letters(x)));
	}
	return total;
}

int main()
{
	std::ifstream is("day_one_input.txt");
	std::istream_iterator<std::string> start(is), end;
	std::vector<std::string> vec(start, end);
	int total = day_one(vec);
	std::cout << total << "\n";
	return total;
}