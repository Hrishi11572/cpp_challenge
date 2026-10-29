#include <iostream>
#include <thread>
#include <future>

void take_your_time() {
    for(long long i=1; i<(long long)(1e9); i+=1) {}; 
    std::cout << "function finished!" << std::endl; 
    return; 
}

int main() {
    std::cout << "start of program" << std::endl;
    std::future<void> ticket = std::async(std::launch::async, take_your_time);
    ticket.get(); 
    std::cout << "main function continues!" << std::endl; 
    std::cout << "end of program" << std::endl;
}

/*


    std::cout << "Main is doing other work...\n";

    int answer = ticket.get();  // wait for the result and collect it

    std::cout << "Answer: " << answer << "\n";

*/