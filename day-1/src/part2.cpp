#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <regex>

int calibrate(std::string input) {
    std::stringstream ss(input);
    std::vector<int> nums;
    int answer = 0;
    std::string word_numbers[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    // Loop over lines
    for (std::string line; std::getline(ss, line, '\n');) {

        for (int i=0; i<sizeof(word_numbers)/sizeof(std::string); i++) {
            line = std::regex_replace(line, std::regex(word_numbers[i]), (char)(i+'1'));
        }
        // Create vector to store digits to then convert back
        std::vector<int> digits;

        // Loop over characters in line
        for (int i = 0; i<line.length(); i++) {
            // Check if character is a digit
            if (std::isdigit(line[i])) {
                // Convert and push it to the digits vector
                int digit = (line[i]-'0');
                digits.push_back(digit);
            }
        }
        // Create 2 digit number with first and last digit in the array then push it to the nums vector
        int num = digits[0]*10+digits[digits.size()-1];
        nums.push_back(num);
    }
    // Sum elements in nums
    for (int i = 0; i<nums.size(); i++)
        answer = answer + nums[i];
    return answer;
}

int main() {
    const std::string test_input = "two1nine\n"
                                   "eightwothree\n"
                                   "abcone2threexyz\n"
                                   "xtwone3four\n"
                                   "4nineeightseven2\n"
                                   "zoneight234\n"
                                   "7pqrstsixteen\n";
    const std::string real_input = {
#include "part1.txt"
    };
    int test_output = calibrate(test_input);
    int actual_output = calibrate(real_input);
    std::cout << "Test Output: " << test_output << std::endl;
    std::cout << "Actual Output: " << actual_output << std::endl;
    return 0;
}
