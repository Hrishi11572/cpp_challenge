#include<iostream>

class Gandalf {
public: 
    int* data; 
    // constructor for new object creation 
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

// BELOW IS THE WRONG CLASS -- SHALLOW COPY CASE

class Sauron {
public: 
    int* data; // for classes containing pointers, this type of construction is erroneous 

    Sauron (int value) 
            : data(new int (value)) {}; 

    ~Sauron () {
        delete data; 
    }
};

int main() {
    Gandalf a(34); 
    Gandalf b = a; 

    std::cout << "Data of a : " <<  *a.data << std::endl;
    std::cout << "address of a's data pointer : " <<  &a.data << std::endl;
    
    std::cout << "Data of b : " <<  *b.data << std::endl;
    std::cout << "address of b's data pointer : " <<  &b.data << std::endl;
    
    /*------------Code below throws error----------------------*/
    // Sauron A(23); 
    // Sauron B = A;

    // std::cout << "Data of A : " <<  *A.data << std::endl;
    // std::cout << "address of A's data pointer : " <<  &A.data << std::endl;
    // std::cout << "Data of B : " <<  *B.data << std::endl;
    // std::cout << "address of B's data pointer : " <<  &B.data << std::endl;
    
    return 0; 
}

/* 
    SAMPLE OUTPUT: 
    Data of a : 34
    address of a's data pointer : 0x16bbc2680
    Data of b : 34
    address of b's data pointer : 0x16bbc2678

    same value stored, but the pointers are different. 
*/