/* More on Copy Assignment */
#include <iostream> 

class Gandalf {
public: 
    int* data; 
    // constructor for copy 
    explicit Gandalf(int value)
            : data(new int (value)) {}; 
            
    // the copy constructor for deep-copy 
    Gandalf(const Gandalf& other)
            : data(new int (*other.data)) {};
    
    // copy assignment operator overloading 
    Gandalf& operator=(const Gandalf& other){
        if (this != &other) {
            *data = *other.data; 
        }
        return *this; 
    }


    ~Gandalf() {
        delete data; 
    }
};

int main() {
    Gandalf a(23); 
    Gandalf b(4); 

    std::cout << "Values pre assignment " << std::endl; 
    std::cout << "*a.data = " << *a.data << " , &a.data  = " << &a.data << std::endl;
    
    std::cout << "*b.data = " << *b.data << " , &b.data = " << &b.data << std::endl; 

    // assignment 
    b = a; 

    std::cout << "Values POST assignment " << std::endl; 
    std::cout << "*a.data = " << *a.data << " , &a.data  = " << &a.data << std::endl;
    
    std::cout << "*b.data = " << *b.data << " , &b.data = " << &b.data << std::endl;    
}