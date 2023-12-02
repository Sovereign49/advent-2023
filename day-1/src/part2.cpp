#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>

const std::string word_numbers[9] = {
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
};

int calibrate(std::string input) {
    std::stringstream ss(input);
    std::vector<int> nums;
    int answer = 0;

    // Loop over lines
    for (std::string line; std::getline(ss, line, '\n');) {
        std::cout << line << std::endl;
        // Create vector to store digits to then convert back
        int leftnum = 0;
        int rightnum = 0;

        // Loop over characters in line
        for (int i = 0; i<line.length(); i++) {
            // Check if character is a digit
            if (std::isdigit(line[i])) {
                int digit = (line[i]-'0');
                if(!leftnum) {
                    leftnum = digit;
                }
                else {
                    rightnum = digit;
                }
            }
            else {
                for (int j=0; j<9; j++) {
                    std::string num_word = word_numbers[j];
                    if (num_word.size() > line.length()-i)
                        continue;
                    std::string word = line.substr(i,num_word.size());
                    if (num_word == word) {
                        std::cout << "Got a match: " << j+1 << " at " << i << std::endl;
                        if(!leftnum) {
                            leftnum = j+1;
                        }
                        else {
                            rightnum = j+1;
                        }
                        break;
                    }
                }
            }
        }
        // Create 2 digit number with first and last digit in the array then push it to the nums vector
        int num = leftnum*10+rightnum;
        std::cout << num << std::endl;
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
#include "part2.txt"
    };
    int test_output = calibrate(test_input);
    std::cout << "Test Output: " << test_output << std::endl;
    int actual_output = calibrate(real_input);
    std::cout << "Actual Output: " << actual_output << std::endl;
    return 0;
}
