/* 
    Here, i highlight the problem with  `.detach()`, 

    Imagine a function starts a detached worker that accesses a local variable by reference:
    
    After start_work() returns, value no longer exists. If the worker accesses it afterward, the program has undefined behavior.

    The problem is not merely that the thread is detached. The problem is that its lifetime exceeds the lifetime of the object it accesses.
*/

#include<iostream>
#include<thread>

int main() {
    int value = 42; 

    std::thread t(
        [&value] {
            std::cout << "Value = " << value << std::endl; 
        }
    );

    t.detach(); 
    
    // jthread handles joining in the destructor itself. 
    std::jthread worker([] {
        std::cout << "Worker is running\n";
    });
    return 0; 
}