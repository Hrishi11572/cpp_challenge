#pragma once 

#include <cstddef>

class Buffer {
public: 
    // call constructor 
    explicit Buffer(std::size_t n); 
    
    // deep copy 
    Buffer(const Buffer& other);

    // copy assignment 
    Buffer& operator=(const Buffer& other); 

    // move constructor 
    Buffer(Buffer&& other) noexcept; 

    // move assignment 
    Buffer& operator=(Buffer&& other) noexcept; 

    // resize method 
    void resize(const int); 

    // operator [] | random access 
    int& operator[](std::size_t idx);
    
    const int& operator[](std::size_t idx) const;

    // destructor 
    ~Buffer();

private: 
    std::size_t size_ {0}; 
    int* data_ {nullptr};     
}; 

/* 
Design decision : 

the data members of the class should be private, otherwise someone can modify the state of the object. 
ex. Obj b.data= nullptr ; loosing the pointer to the memory in heap, causing memory leakage. 
*/