#include <exception>
#include <iostream>
#include <stdexcept>
#include <thread>

void work() {
    try {
        throw std::runtime_error("Calculation failed");
    } catch (const std::exception& e) {
        std::cerr << "Worker error: " << e.what() << '\n';
    }
    // throw std::runtime_error("Calculation failed");
}

int main() {
    std::thread t(work);
    t.join();

    std::cout << "Main continues\n";
}