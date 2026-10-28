#include <iostream>
#include <stdexcept>


double divide(double a, double b) {
    if(b == 0) {
        throw std::invalid_argument("divisor can not be 0"); 
    }

    return a/b; 
}


int main() {
    // try-catch block 
    try {
        double res = divide(10, 0); 
        std::cout << res << std::endl;
    }catch(const std::invalid_argument& e) {
        std::cerr << "ERROR occured : " << e.what() << std::endl; 
    }

    std::cout << "Main function continues!" << std::endl; 
}