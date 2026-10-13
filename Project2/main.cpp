#include<iostream>
#include "Buffer/engine.hpp"

int main() {
    Buffer a = {1, 2, 3, 4, 5}; 
    std::cout << a[4] << std::endl; 
    return 0; 
}