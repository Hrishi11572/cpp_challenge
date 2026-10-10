#include<iostream>
#include<set>
#include "stats.hpp"

class FileStats {
private: 
    std:: size_t line_counts; 
    std:: size_t word_counts; 
    std:: size_t byte_counts; 
public:
    std :: size_t get_line_counts() const {
        return line_counts; 
    }
    std :: size_t get_word_counts() const {
        return word_counts; 
    }
    std :: size_t get_byte_counts() const {
        return byte_counts; 
    }

    void calculate_file_stats(const std::string& contents) {
        std :: size_t _lines =0; 
        std :: size_t _words =0; 
        std :: size_t _bytes =0;

        std:: set<std::size_t> st; 

        // calculating the number of lines 
        for (char c : contents){
            if (c == '\n') _lines++; 
            st.insert(c); 
            _bytes += 1 * sizeof(c); 
        }

        line_counts = _lines; 

        // calculating the number of words
        _words = st.size(); 
        word_counts = _words; 

        // calculating the number of bytes 
        byte_counts = _bytes; 
    }
};
