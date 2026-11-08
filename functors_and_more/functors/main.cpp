/*
A functor (function object) is an object of a class or struct that can be called like a normal function.
*/

#include<iostream>

class Add {
private:
    // none as of now
public:
    int operator()(int a, int b) {
        return a + b; 
    }
};

int main() {
    Add a;  
    std::cout << a(10, 20) << std::endl; 
    return 0;
}