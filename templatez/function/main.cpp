// On function templates 

#include<iostream>

template <typename T>
T add(T a, T b) {
    return a + b; 
}

int main() {
    int i; 
    float f; 
    double d; 
    long long l; 
    
    i = add(1, 2); 
    f = add(2.3, 4.56); 
    d = add(2.3456, 45.23); 
    l = add(1e11, 1e12); 

    std::cout << i << std::endl; 
    std::cout << f << std::endl; 
    std::cout << d << std::endl; 
    std::cout << l << std::endl; 
    
    return 0; 
}