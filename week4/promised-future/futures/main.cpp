
#include <future>
#include <iostream>

int main() {
    std::future<int> f = std::async([] {
        return 42;
    });

    int result = f.get();

    std::cout << result << '\n';  // 42
}

/*
    - std::async(...) launches a task, potentially on another thread.
    - std::future<int> represents the task's eventual integer result.
    - f.get() obtains that result, waiting if necessary.
*/