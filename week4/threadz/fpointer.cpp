/*
What is all with function pointers ? 
*/
#include <iostream>

int foo() // code starts at memory address 0x002717f0
{
    return 5;
}

int main()
{
    // std::cout << foo << '\n'; // we meant to call foo(), but instead we're printing foo itself!

    // std::cout << reinterpret_cast<void*>(foo) << '\n'; // Tell C++ to interpret function foo as a void pointer (implementation-defined behavior)

    // return 0;

    int (*fcnPtr)(){ &foo }; // Initialize fcnPtr with function foo

    int p = 0; 
    if(fcnPtr)  p = fcnPtr(); // call function foo() through fcnPtr.
    std::cout << "Value Received = " << p << std::endl; 
    return 0;

}