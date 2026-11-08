
#include <iostream>
#include <stdexcept>

void process(int value) {
    if (value < 0) {
        throw std::invalid_argument("Negative value");
    }

    if (value > 100) {
        throw std::out_of_range("Value exceeds limit");
    }

    std::cout << "Processing " << value << '\n';
}

int main() {
    try {
        process(-4);
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Input error: " << e.what() << '\n';
    }
    catch (const std::out_of_range& e) {
        std::cout << "Range error: " << e.what() << '\n';
    }
    catch (const std::exception& e) {
        std::cout << "Other error: " << e.what() << '\n';
    }
}
