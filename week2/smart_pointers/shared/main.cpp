#include <iostream>
#include <memory>

int main() {
    auto p1 = std::make_shared<int>(42);
    auto p2 = p1;

    std::cout << *p1 << '\n';
    std::cout << *p2 << '\n';
    std::cout << p1.use_count() << '\n';
}

// Both pointers refer to the same integer. Copying a shared_ptr creates another owner; it does not copy the integer itself.