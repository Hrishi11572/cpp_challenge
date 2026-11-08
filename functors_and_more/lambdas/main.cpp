/* On lambdas */

/* 
    General Structure - 

[capture_list](parameters) -> return_type {
    // function body
};

Capture	     |         What happens?
[x]	                   Captures x by value
[&x]	               Captures x by reference
[=]	                   Captures used local variables by value
[&]	                   Captures used local variables by reference
[=, &x]	               Everything by value, except x by reference
[&, x]	               Everything by reference, except x by value

*/

#include<iostream>

int main() {
    int a = 2; 
    int b = 4; 

    auto add = [](int a, int b) {
        return a+b; 
    };

    int factor = 5;
    auto multiply = [&factor](int x) {
        return x * factor;
    };

    factor = 100;

    std::cout << multiply(10) << "\n"; 
    std::cout << add(a, b)<< "\n"; 

    return 0; 
}

/* 
Rough mental model for compiler generated code: 

int factor = 5;

auto multiply = [factor](int x) {
    return x * factor;
};
cout << multiply(10);
            |
            |
            |
            V
class Generated {
    int factor;

public:
    Generated(int f) : factor(f) {}

    int operator()(int x) const {
        return x * factor;
    }
};
*/