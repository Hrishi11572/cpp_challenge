// on atomic variable

#include<iostream>
#include<thread>
#include<mutex>
#include<atomic>

// int x; 

std::atomic<int> x = 0; 

void incrementCounter() {
    x += 1; 
    return; 
}

int main() {
    std::thread t1(incrementCounter); 
    std::thread t2(incrementCounter); 

    t1.join(); 
    t2.join(); 

    std::cout << "threads already joined \nValue = " << x << std::endl; 
    return 0;
}

