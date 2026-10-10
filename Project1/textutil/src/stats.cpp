#include<iostream>
#include<set>
#include<sstream>
#include "textutil/stats.hpp"


std :: size_t FileStats::get_line_counts() const {
    return line_counts; 
}

std :: size_t FileStats::get_word_counts() const {
    return word_counts; 
}

std :: size_t FileStats::get_byte_counts() const {
    return byte_counts; 
}

void FileStats::calculate_file_stats(const std::string& contents) {

    std :: size_t _lines =0; 
    std :: size_t _words =0; 
    std :: size_t _bytes =0;

    // calculating the number of lines 
    std:: set<std::size_t> st; 
    for (char c : contents){
        if (c == '\n') _lines++; 
        _bytes += 1 * sizeof(c); 
    }

    line_counts = _lines; 

    // calculating the number of words
    std::stringstream ss(contents);
    std::string word; 
    
    while(ss >> word){
        _words++; 
    }
    word_counts = _words; 

    // calculating the number of bytes 
    byte_counts = _bytes; 
}

