/* Here we discuss the need for function pointers */

/*
Suppose you want to write a function that accepts another function as an argument and performs the corresponding operation.

We can do that using function pointers!
*/

#include<iostream>

int add(int a, int b) {return a + b;} 
int subtract(int a, int b) {return a - b;}
int multiply(int a, int b) {return a * b;} 


int calculate(int a, int b, int (*fpointer) (int, int)){
    return fpointer(a, b); 
}


int main() {
    int V1 = 12; 
    int V2 = 23; 

    std::cout << "utility of function pointers" << "\n"; 
    std::cout <<"add : " << calculate(V1, V2, add) << "\n"; 
    std::cout <<"subtract : " << calculate(V1, V2, subtract) << "\n"; 
    std::cout <<"multiply : " << calculate(V1, V2, multiply) << "\n"; 

    return 0; 
}