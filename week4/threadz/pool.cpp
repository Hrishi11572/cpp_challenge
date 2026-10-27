#include<iostream>
#include<thread>
#include<vector>

int main() {
    // lambda function
    auto lambda = [](int x) {
        std::cout << "thread id : " << std::this_thread::get_id() << std::endl; 
        std::cout << "Argument passed in " << x << std::endl; 
    };

    std::vector<std::thread> threads; 

    for(int i = 0; i < 10; i++) {
        threads.push_back(std::thread(lambda, i)); 
    }

    // join all threads to main thread; 
    for (int i=0; i<10; i++) threads[i].join(); 

    std::cout << "Before Joining threads in the main function" << std::endl; 
    return 0; 
}