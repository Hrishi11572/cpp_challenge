// clang++ -std=c++20 -Wall -Wextra -g -O1 -pthread main.cpp -o main  

#include <iostream>
#include <thread>
#include <string>
#include <vector>

void greet(const std::string& who, int times) {
    for(int i=0; i<times; i++) {
        std::cout << "Hello, " + who + "\n"; 
    }
}

struct Counter {
    int value = 0; 
    void add(int n) { value += n; }; 
};

struct Worker {
    int id; 
    void operator()() const {
        std::cout << "functor worker " + std::to_string(id) + "\n"; 
    }
};

int main() {

    std::cout << "start of the program" << std::endl; 

    std::thread t1(greet, "alice", 3); 
    std::thread t2([] {std::cout << "hello from a lambda\n";});

    std::thread t3(Worker{7});

    Counter c; 
    std::thread t4(&Counter::add, &c, 43); 

    t1.join(); // that's a wait statement 
    t2.join(); 
    t3.join(); 
    t4.join();

    std::cout << "counter = " << c.value << std::endl; 

    return 0; 
}
