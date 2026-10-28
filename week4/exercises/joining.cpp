// .join() stops the main thread until the worker finishes. 

#include <iostream>
#include <thread>

void calculate() {
    int result = 20 * 30;
    std::cout << "Result: " << result << '\n';
}

int main() {
    std::thread worker(calculate);

    std::cout << "Waiting for calculation...\n";
    worker.join();

    std::cout << "Calculation finished.\n";
}