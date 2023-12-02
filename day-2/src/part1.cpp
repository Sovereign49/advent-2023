#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

enum Color {
    red, green, blue
};

Color toColor(std::string input) {
    if(input == "red") return red;
    else if(input == "green") return green;
    else if(input == "blue") return blue;
    // ignore this
    else return red;
}

int solution(std::string input) {
    std::stringstream s(input);
    std::string split;
    int id = 0;
    while (std::getline(s,split,':')) {
        if (split.substr(0,4) == "Game") {
            id = split[split.size()-1] - '0';
        }
        //todo else block
        std::cout << split << std::endl;
    }
    return -1;
}

int main() {
    // file input
    std::ifstream f("input/part1.txt");
    std::stringstream buffer;
    buffer << f.rdbuf();
    const std::string real_input = buffer.str();

    std::string test_input = "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green\n"
                             "Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue\n"
                             "Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red\n"
                             "Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red\n"
                             "Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green\n";

    int test_output = solution(test_input);

    std::cout << "Hello Part 1!" << std::endl;
    return 0;
}
