#include<iostream>
#include<stdexcept>

double safeDiv(double a, double b) {
    if(b == 0.0) throw std::invalid_argument("can't divide by 0"); 

    return a/b; 
}

int main() {
    try{
        std::cout << safeDiv(10, 3) << "\n";  
        std::cout << safeDiv(10, 1) << "\n";
        std::cout << "not printed!" << "\n"; 
    }catch(const std::invalid_argument& e) {
        std::cerr << "ERROR : " << e.what() << "\n"; 
    }
    return 0;
}