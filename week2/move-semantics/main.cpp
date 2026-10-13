#include <iostream>
#include <utility>

class Buffer {
private: 
    std::size_t size_ {0}; 
    int * data_ {nullptr}; 

public: 
    // the genuine constructor 
    explicit Buffer(std::size_t n )
            : size_(n), data_(n ? new int [n] : nullptr) {}; 

    // the genuine destructor 
    ~Buffer() {
        delete[]  data_; 
    }

    // move operator . . .
    Buffer(Buffer&& other) noexcept 
            : size_(other.size_), data_(other.data_) 
    {
        other.size_ = 0; 
        other.data_ = nullptr; 
    }
};

int main() {
    Buffer a(10);

    try {
        Buffer b = std::move(a);

        std::cout << "Program successfully executed\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Error occurred: " << e.what() << '\n';
        return 1;
    }
    return 0;
}