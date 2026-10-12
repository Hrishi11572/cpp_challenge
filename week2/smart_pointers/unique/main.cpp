#include <iostream>
#include <memory>
#include<utility>


int main() {
    auto p = std::make_unique<int>(5); 

    std::cout << "Value in p before moving : " << *p << std::endl; 

    // you can not copy a unique_ptr
    // auto q = p; // this throws error 

    // you can only move the ownership 
    auto q = std::move(p); // p becomes 0 

    std::cout << "Value in q : " <<  *q << std::endl; 
    std::cout << "q : " << q << std::endl; 
    std::cout << "Value in p after moving : "; 
    std::cout <<p << std::endl; 
    return 0; 
}