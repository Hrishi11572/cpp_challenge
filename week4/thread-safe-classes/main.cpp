/*
Three simple rules for thread-safe classes:

    1. Keep the mutex private, next to the data. Users of the class should never have to
       lock anything themselves.

    2. Return copies, not references. A reference to the inside data would let someone use it
       after the lock is gone.

    3. Do the whole job in one method. Checking and then acting in two separate calls is not
       safe:
*/

#include<iostream>
#include<thread>
#include<thread>
#include<functional>
#include<mutex>

class threadSafeClass {
public : 
    int get() {
        std::lock_guard<std::mutex> lock(m); 
        return data; 
    }

    void add(int n) {
        std::lock_guard<std::mutex> lock(m); 
        data += n; 
    }
private: 
    std::mutex m; 
    int data{0};  
};

int main () {
    threadSafeClass c; 
    std::thread t1([&c] {
        for (int i=0; i<100; i++) {
            c.add(1); 
        }
    }); 
    std::thread t2([&c] {
        for (int i=0; i<100; i++) {
            c.add(1); 
        }
    }); 

    t1.join(); 
    t2.join();

    std::cout << c.get() << std::endl; 
    return 0; 
}