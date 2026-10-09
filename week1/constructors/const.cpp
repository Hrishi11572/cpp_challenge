#include<iostream>

class constPoint {
private : 
    const int constant_value; 

public: 
    // this throws error as members are initialized first and then re-assignment takes place. Which throws error in case of const variable.

    // constPoint(int c) {
    //     constant_value = c; 
    // }

    // Here the memebers are initialized with their intended values directly
    constPoint(int c):
        constant_value(c) {}
    
    int get() {
        return this->constant_value; 
    }
};


int main() {
    constPoint cP = {5}; 
    std :: cout <<  cP.get()  << std :: endl; 
    return 0; 
}