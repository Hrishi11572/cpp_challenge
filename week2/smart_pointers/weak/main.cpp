#include <iostream>
#include <memory>


int main() {
    auto owner = std::make_shared<int>(42); 
    std::weak_ptr<int> observer = owner; 

    std::cout << owner << std::endl; 
    std::cout << observer.lock() << std::endl; // direct dereferencing doesn't work

    std::cout << *owner << std::endl;  /* dereferencing the owner */
    std::cout << *observer.lock() << std::endl; /* dereferencing observer */
    return 0; 
}







