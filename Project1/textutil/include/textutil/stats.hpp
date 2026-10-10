#pragma once

#include<cstddef> // for size_t

class FileStats {
private: 
    std:: size_t line_counts {0}; 
    std:: size_t word_counts {0}; 
    std:: size_t byte_counts {0}; 
public:
    std :: size_t get_line_counts() const; 
    std :: size_t get_word_counts() const; 
    std :: size_t get_byte_counts() const; 
};