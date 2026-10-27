// Refer to the notes on threads

#include <iostream>
#include <thread>
#include <functional>
#include <memory>

void increment(int& x) {x+=1;}

void consume (std::unique_ptr<int> p) {
    std::cout << "*p = " << *p << std::endl; 
    return; 
}

int main() {
    int value = 0; 

   //  std::thread t(increment,value); this doesn't compile
   //  t.join(); 

   // std::thread t(increment, &value); this doesn't compile either 
   //  t.join(); 

    std::cout << "Value before thread starts = " << value << std::endl; 

    std::thread t(increment, std::ref(value)); 

    std::cout << "Value before thread joins = " << value << std::endl; 

    t.join(); 

    std::cout << "Value after thread joins = " << value << std::endl; 
    return 0; 
}