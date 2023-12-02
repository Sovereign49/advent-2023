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

int solution(std::string input) {
    std::stringstream input_stream(input);
    std::string split;
    int id = 0;
    int answer = 0;
    std::vector<int> possible_games;

    while (std::getline(input_stream,split,':')) {
        if (split.substr(0,4) == "Game") {
            id = split[split.size()-1] - '0';
            std::cout << split << std::endl;
        }
        else {
            std::stringstream game_stream(split);
            std::string game_split;
            bool is_possible = true;
            while (std::getline(game_stream, game_split, ';')) {
                std::stringstream color_stream(game_split);
                std::string color_split;
                while (std::getline(color_stream, color_split, ',')) {
                    color_split = color_split.substr(1);
                    std::stringstream number_stream(color_split);
                    std::string number_split;
                    int number = 0;
                    while (std::getline(number_stream, number_split, ' ')) {
                        if (isdigit(number_split[1])) {
                            number = std::stoi(number_split);
                        }
                        else {
                            Color color = toColor(number_split);
                            switch (color) {
                            case red:
                                is_possible = (number <= 12);
                            case green:
                                is_possible = (number <= 13);
                            case blue:
                                is_possible = (number <= 14);
                            }
                        }
                        std::cout << number_split << std::endl;
                    }
                }
            }
            if (is_possible) {
                possible_games.push_back(id);
            }
        }
    }
    for (int i=0; i<possible_games.size(); i++) {
        answer = answer + possible_games[i];
        std::cout << possible_games[i] << std::endl;
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
