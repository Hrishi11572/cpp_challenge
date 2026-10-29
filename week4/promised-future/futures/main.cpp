#include <future>
#include <iostream>

int main() {
    std::future<int> f = std::async([] {
        return 42;
    });

    int result = f.get();

    std::cout << result << '\n';  // 42
}