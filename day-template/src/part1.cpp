#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

int solution(std::string input) {
    return -1;
}

int main() {
    // file input
    std::ifstream f("input/part1.txt");
    std::stringstream buffer;
    buffer << f.rdbuf();
    const std::string real_input = buffer.str();

    std::cout << "Hello Part 1!" << std::endl;
    return 0;
}
