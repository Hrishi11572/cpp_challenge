// On class templates 

#include<iostream>
#include<cstddef>

template <typename T>
class Buffer {
private: 
    T* data; 
    std::size_t size; 
public: 
    Buffer(std::size_t n): 
        size(n) {
        data = new T[n]; 
    }

    ~Buffer() {
        delete[] data; 
    }    
    
    T& operator[](std::size_t i) {
        return data[i]; 
    }
};

int main() {

    Buffer<int> a(10);

    Buffer<double> b(20);

    Buffer<float> c(30);

    a[0] = 100;
    b[0] = 3.14159;
    c[0] = 2.5f;

    std::cout << a[0] << '\n';
    std::cout << b[0] << '\n';
    std::cout << c[0] << '\n';
}
