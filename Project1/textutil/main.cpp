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
#include "textutil/stats.hpp"
#include "textutil/file_io.hpp"



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
        const std::string file_path = argv[argc-1]; 
        const std::string contents = read_file_contents(file_path); 

        FileStats stats;
        stats.calculate_file_stats(contents);

        std::cout << "Lines : " << stats.get_line_counts() << std::endl; 
        std::cout << "Word : " << stats.get_word_counts() << std::endl; 
        std::cout << "Bytes : " << stats.get_byte_counts() << std::endl; 
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