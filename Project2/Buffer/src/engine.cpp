#include "Buffer/engine.hpp"
#include<iostream>
#include<algorithm>


// call constructor 
Buffer::Buffer(std::size_t n)
            : size_(n), data_(n ? new int [n]{0}: nullptr) {}; 
    
// destructor 
Buffer::~Buffer() {
    delete[] data_; 
}

// constructor for deep copy 
Buffer::Buffer(const Buffer& other)
            : size_(other.size_), data_(other.size_ ? new int [other.size_]: nullptr) {
    if (size_ > 0) {
        std::copy(other.data_,
                  other.data_ + size_,
                  data_);
    }
}; 

// copy-assignment | operator overloading 
Buffer& Buffer::operator=(const Buffer& other) {
    if(this == &other) {
        return *this; 
    }

   int* new_data = nullptr; 

   if(other.size_ > 0) {
        new_data = new int [other.size_]; 
        std::copy(other.data_, other.data_ + other.size_, new_data); 
   }

    delete [] data_; 

    data_ = new_data; // the variable new_data will get deleted, as soon as it gets out of scope an then only data_ remains.
    size_ = other.size_; 

    return *this; 
}

// move semantics 
Buffer::Buffer(Buffer&& other) noexcept
    : size_(other.size_), data_(other.data_)
{
    other.size_ = 0;
    other.data_ = nullptr;
}

// move assignment operator | op overloading 
Buffer& Buffer::operator=(Buffer&& other) noexcept {

    if(this != &other) {
        delete [] data_;

        size_ = other.size_;  
        data_ = other.data_; 

        other.size_ = 0; 
        other.data_ = nullptr;
    }

    return *this; 
}

void Buffer::resize(const int n) {
    // resize the Buffer to n 

    if(n == size_) {
        return; 
    }

    if (n == 0) {
        size_ = 0; 
        delete [] data_; 
        data_ = nullptr; 
    }

    int * new_buffer = new int [n] {}; 
    size_t count = (n > size_) ? size_ : n; 

    std::copy(data_, data_ + count, new_buffer); 
    delete [] data_; 

    data_ = new_buffer; 
    size_ = n; 
}

int& Buffer::operator[](std::size_t idx) {
    if (idx >= size_) {
        throw std::out_of_range("Buffer index out of range");
    }

    return data_[idx]; 
}

const int& Buffer::operator[](std::size_t idx) const {
    if (idx >= size_) {
        throw std::out_of_range("Buffer index out of range");
    }

    return data_[idx]; 
}