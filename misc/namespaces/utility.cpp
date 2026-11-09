/*
An inner scope can access variables from its enclosing scopes, but an outer scope cannot access variables declared inside an inner scope.
*/

#include<iostream>
int x = 42;

int main() {
    int y = 123; 
    std::cout << "Entering into the scope\n";
    {
        int x = 100; 
        std::cout << "Local x : " << x << "\n"; 
        std::cout << "Gloabl x : " << ::x << "\n"; 
        std::cout << "y from main scope : " << y << "\n"; 
        std::cout << "Exiting the scope\n";
    }
    return 0; 
}