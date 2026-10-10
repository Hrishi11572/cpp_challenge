/*
Defining CLI structure: 

textutil stats <input-file>
textutil search <input-file> <query>
textutil report <input-file> <output-file>
textutil --help
textutil --version
*/

#include<iostream>
#include<string_view>
#include "textutil/search.hpp"


int main(int argc, char* argv[]) {
    if(argc < 2){
        std::cerr << "Usage: textutil <command> [arguments]\n";
        return 1; 
    }

    const std :: string_view command {argv[1]}; 

    if (command == "--help") {
        std::cout
            << "Usage:\n"
            << "  textutil stats <input-file>\n"
            << "  textutil search <input-file> <query>\n"
            << "  textutil report <input-file> <output-file>\n";
        return 0;
    }
    if (command == "stats") {
        if (argc != 3) {
            std::cerr << "Usage: textutil stats <input-file>\n";
            return 1;
        }

        // TODO: Calculate and print statistics.
        std::cout << "DO SOME STATS" << std::endl; 
        return 0;
    }

    if (command == "search") {
        if (argc != 4) {
            std::cerr << "Usage: textutil search <input-file> <query>\n";
            return 1;
        }

        // TODO: Search the file.
        return 0;
    }

    if (command == "report") {
        if (argc != 4) {
            std::cerr
                << "Usage: textutil report <input-file> <output-file>\n";
            return 1;
        }

        // TODO: Generate the report.
        return 0;
    }

    std::cerr << "Unknown command: " << command << '\n';
    std::cerr << "Run 'textutil --help' for usage.\n";
    return 1;
}