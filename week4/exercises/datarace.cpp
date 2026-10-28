#include <iostream>
#include <thread>

int counter = 2;

void increment() {
    ++counter;
}

int solve() {
    std::thread a(increment);
    std::thread b(increment);

    a.join();
    b.join();

    return counter; 
}


int main() {
    int localcnt = 0; 
    while(counter == 2){
        counter = 0; 
        solve(); 
        localcnt++; 
        std::cout << counter << std::endl; 
    } 

    std::cout << localcnt << std::endl; 
    return 0; 
}