#pragma once

#include<cstddef> // for size_t

class FileStats {
private: 
    const std :: string file;
    std:: size_t line_counts {0}; 
    std:: size_t word_counts {0}; 
    std:: size_t byte_counts {0}; 
public:
    std :: size_t get_line_counts() const; 
    std :: size_t get_word_counts() const; 
    std :: size_t get_byte_counts() const; 
    void calculate_file_stats(const std::string& contents) const;
};