#include<iostream>

class CachedValue {
private: 
    int value_{43}; 
    mutable bool cached_{false}; // mutable keyword allows to edit the private variable

public: 
    int value() const {
        cached_ = true; 
        return cached_; 
    }
};

int main() {
    CachedValue C; 
    std :: cout << C.value() << std :: endl; 
    return 0; 
}