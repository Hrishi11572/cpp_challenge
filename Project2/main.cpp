#include<iostream>
#include "Buffer/engine.hpp"

int main() {
    Buffer a = {1, 2, 3, 4, 5}; 
    // std::cout << a[4] << std::endl; 

    std::cout << "Buffer a : " << a << std::endl; 

    Buffer b = std::move(a); 

    std::cout << "Buffer b : " << b << std::endl; 
    std::cout << "Buffer a : " << a << std::endl; 

    b.resize(3); 
    Buffer d = b; 


    std::cout << b << std::endl; 

    Buffer c = {3, 4, 6, 9, 0, 12, -1}; 
    b = c; // copy assignment 

    std::cout << "Buffer c : " << c << std::endl; 
    std::cout << "Buffer b : " << b << std::endl; 

    std::cout << "Buffer d : " << d << std::endl; 
    return 0; 
}