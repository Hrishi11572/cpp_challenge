#include<iostream>

int addNumbers(int a, int b) { return a + b;}

int main() {
    int (*ptr)(int,int) = &addNumbers; // only addNumbers also works
    // call the function 
    std::cout << ptr(23, 4) << "\n"; // can also write (*ptr)(23, 4); 
    return 0; 
}

/*
general syntax of function pointer

{function return type} (*{name of pointer}(paramete-1 type, parameter-2 type, ...))
*/