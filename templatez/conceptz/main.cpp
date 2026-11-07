#include<iostream>
#include<concepts>
#include<vector>

template<typename T> 
concept Numeric = std::integral<T> || std::floating_point<T>; 

template<Numeric T>
T average(const std::vector<T>& v) {
    T sum{};
    for(const T &val : v){
        sum += val; 
    }

    return !v.empty() ? sum / static_cast<T>(v.size()) : T{}; 
}

int main() {
    std::cout << "may god bless you!" << std::endl; 
    // std::vector v {"marry", "me", "will", "ya", "?"}; ... doesn't compile
    std::vector<double> v {1.0, 2.0, 3, 4, 5}; 

    std::cout << average(v) << std::endl; 
    return 0; 
}