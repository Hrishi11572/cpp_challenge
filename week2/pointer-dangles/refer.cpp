#include <iostream>

void change(std::string& n) {
    // change the string. 
    n = "zzzz"; 
}

int main() {
    std::string x = "abcs"; 
    change(x); 
    // change(&x) ... please don't do this mistake. 
    std::cout << x << std::endl; 
    return 0; 
}