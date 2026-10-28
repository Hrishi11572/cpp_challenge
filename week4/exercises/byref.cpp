/* 
    1. How are arguments passed to threads?

    - By default, std::thread stores copies or moves of the arguments you pass into it. Those stored arguments are then used to invoke the function.

    2. But what if the function expects a reference ? 
    -  std::thread t(increment, value);  .... throws compilation error 
    -  std::thread t(increment, &value); .... throws compilation error 

*/
#include<iostream>
#include<thread>
#include<functional>

void increment(int& x) { ++x; }

int main() {

    int value = 0; 
    
    std::cout << "Value : " << value << std::endl; 

    std::thread t(increment, std::ref(value)); 
    t.join(); 

    std::cout << "Value : " << value << std::endl; 
    return 0; 
}