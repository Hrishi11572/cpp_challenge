#include<iostream>

int add(int, int); 

int main() {
    int a = 3; 
    int b = 4; 

    std::cout << add(a , b) << std::endl; 
    return 0; 
}

/*
A separate math.cpp contains the implementation of add; 
we compile both files main.cpp and math.cpp together and see the output. 

Then, we compile main.cpp only, and see the error. This explains the function of Linker

Eror message / clang++: error: linker command failed with exit code 1 (use -v to see invocation)
*/