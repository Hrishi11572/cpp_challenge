// On condition variables - resume when the other thread signals 

#include<iostream>
#include<thread>
#include<mutex> 
#include<condition_variable>

// mutex
std::mutex m; 
std::condition_variable cv; 
bool ready = false; 

void consumer() {
    std::unique_lock<std::mutex> lock(m); 
    // cv.wait(lock, predicate);
    cv.wait(lock, [] {
        return ready; 
    }); 
    std::cout << "Data is ready!" << std::endl; 
}

void producer() {
    {
        std::lock_guard<std::mutex> lock(m); 
        ready = true; 
    }
    cv.notify_one(); 
}

int main () {
    std::thread t1(consumer); 
    std::thread t2(producer); 

    t1.join(); 
    t2.join(); 
    return 0; 
}

/*
Here's the sequence:
    1. Consumer: locks mtx and checks ready. It's false.

    2. Consumer: cv.wait() releases mtx and sleeps.

    3. Producer: acquires the now-available mtx and sets ready = true.

    4. Producer: releases mtx and calls notify_one().

    5. Consumer: wakes, reacquires mtx, and checks ready again. It's true.
*/