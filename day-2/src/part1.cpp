#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

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

std::vector<std::string> split (const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss (s);
    std::string item;

    while (getline (ss, item, delim)) {
        std::stringstream is(item);
        std::string split_item;
        while (getline(is, split_item, '\n')) {
            result.push_back(split_item);
        }
    }

    return result;
}

int solution(std::string input) {
    int answer = 0;
    std::vector<std::string> game_outcomes;
    std::vector<int> possible_games;

    std::vector<std::string> split_input = split(input, ':');

    for (int i=0; i<split_input.size(); i++) {
        std::cout << i << ": " << split_input[i] << std::endl;
    }
    for (int i=0; i<split_input.size(); i++) {
        if (i%2==0) {
            // get id as index of game_outcomes + 1;
            continue;
        }
        else {
            game_outcomes.push_back(split_input[i]);
        }
    }
    for (int i=0; i<game_outcomes.size(); i++) {
        std::cout << i << ": " << game_outcomes[i] << std::endl;
        std::vector<std::string> hands = split(game_outcomes[i], ';');
        for (int i=0; i<hands.size(); i++) {
            std::vector<std::string> colors = split(hands[i], ';');
        }
    }

    return answer;
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
