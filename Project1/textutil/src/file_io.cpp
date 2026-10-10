#include "textutil/file_io.hpp"
#include<fstream>
#include<iostream>
#include<sstream>

std::string read_file_contents(const std::string& file_path){
    std::ifstream file(file_path); 

    if (!file.is_open()){
        std::cerr << "Error Opening File!" << std::endl; 
    }

    std::ostringstream buffer; 
    buffer << file.rdbuf(); 
    
    std:: string file_contents = buffer.str(); 
    return file_contents; 
}