#include <iostream>
#include <thread>
#include <functional>

int value = 0;

void increment(int& x) {
    for(int i=0; i<100000; i++){
        x += 1; 
    }
}

int main() {
    std::thread t1(increment, std::ref(value)); 
    std::thread t2(increment, std::ref(value)); 

    t1.join(); t2.join(); 

    std::cout << "Value = " << value << std::endl; 
    return 0; 
}