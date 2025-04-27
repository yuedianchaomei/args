#include <iostream>
#include <string>
#include <vector>
#include "Parser.h"

int main(int argc, char* argv[]){
    Parser parser(argc, argv);

    if (parser.has("h") || parser.has("help")) {
        parser.printHelp();
        return 0;
    }

    if (parser.has("v") || parser.has("verbose")) {
        std::cout << "Verbose mode enabled\n";
    }

    std::string input_file = parser.get("i", parser.get("input", "default.txt"));
    std::string output_file = parser.get("o", parser.get("output", ""));

    std::cout << "Input file: " << input_file << "\n";
    if (!output_file.empty()) {
        std::cout << "Output file: " << output_file << "\n";
    }

    auto positional = parser.getPositionalArgs();
    if (!positional.empty()) {
        std::cout << "Positional arguments:\n";
        for (const auto& arg : positional) {
            std::cout << "  " << arg << "\n";
        }
    }

    return 0;
}