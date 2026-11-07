// an example of class templates 
#include<iostream>
#include<array>
#include<stdexcept>

template<typename T, std::size_t Capacity = 100>
class Stack {
public: 
    void push(const T& value) {
        if(size_ == Capacity) throw std::overflow_error("stack full!"); 
        data_[size_++] = value; 
    }

    bool empty() const {
        return size_ == 0; 
    }

    std::size_t size() const {
        return size_; 
    }

    T pop(); 

    void  print(); 
private:
    std::array<T, Capacity> data_{}; 
    std::size_t size_{0}; 
};

template< typename T, std::size_t Capacity> 
T Stack<T, Capacity>:: pop() {
    if(this->empty()) throw std::underflow_error("stack empty!");
    return  data_[--size_];
}


template<typename T, std::size_t Capacity>
void Stack<T, Capacity>::print() {
    std::cout << "printing the stack : ";

    if(size_ == 0) {std::cout << "Empty Stack\n"; return;}
    
    for(std::size_t i = 0; i<size_; ++i) {
        std::cout << data_[i] << " "; 
    }
    std::cout << "\n"; 
    return; 
}

int main() {
    Stack<int,10> st; 

    // print empty stack 
    st.print(); 

    st.push(1); st.print();  
    st.push(23); st.print(); 

    std::cout << "st.size() = " << st.size() << std::endl;  
    int a = st.pop();
    std::cout << "a = " << a << std::endl;  
    std::cout << "st.size() = " <<  st.size() << std::endl; 

    st.print(); 
    return 0; 
}