#include "textutil/search.hpp"
#include "textutil/file_io.hpp"
#include<sstream>
#include<iostream>


void find(const std::string& filepath, const std::string query) {
    const std::string contents = read_file_contents(filepath);
    std::stringstream ss (contents); 
    std::string token;
    std::vector<std::string> result;

    // Split based on the '\n' character
    while (std::getline(ss, token, '\n')) {
        result.push_back(token);
    }

    int lines = 1; 
    for(auto sentence :  result){
        std::stringstream ss (sentence); 
        std :: string word; 

        while(ss >> word) {
            if (word == query) {
                std::cout << word << " found at line no. " << lines << std::endl; 
            }
        }

        lines++; 
    }
}