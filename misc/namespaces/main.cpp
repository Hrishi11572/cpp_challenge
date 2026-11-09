#include<iostream>

namespace physics {
    double g = 9.8101; 
    double calculate(double u) {
        return 2.0 * (u/g); 
    }
}

namespace finance {
    double g = 0.05; 
    double calculate(double u) {
        return u * std::pow(g, 2); 
    }
}

// nested namespace resolution 
namespace company::pricing {
    double BlackScholes(double s, double k) {
        return s - k; 
    }
}

// aliasing 
namespace cp = company::pricing; 

int main() {
    double t1 = finance::calculate(3.4);
    double t2 = physics::calculate(5.22); 
    double r =  cp::BlackScholes(3, 1.023); 

    std::cout <<"Finance Namespace : "<< t1 << ", " << "Physics Namespace : " << t2 << "\n"; 

    std::cout << "Nested namespace resolution : " << r << "\n"; 
    return 0; 
}