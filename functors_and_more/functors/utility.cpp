#include<iostream>
#include<vector>
#include<algorithm>

class Comparator {
private: 
    bool ascending; 
public: 
    Comparator(bool asc) : ascending(asc) {};

    bool operator()(int a, int b) {
        if(ascending) {
            return a < b; 
        }
        return a > b; 
    }
};


int main() {
    // vector initialization
    std::vector<int> v {12, 3, -2, 45, 10, 1 , 5, 7}; 

    // sort the vector in ascending order
    std::sort(v.begin(), v.end(), Comparator(true)); 

    for(auto& i : v) {
        std::cout << i << " "; 
    }
    std::cout << "\n"; 

    // sort the vector in descending order 
    std::sort(v.begin(), v.end(), Comparator(false));

    for(auto& i : v) {
        std::cout << i << " ";
    }
    std::cout << "\n"; 
    return 0;
}