// why is this program erroneous. QUESTION 

#include <iostream>

int* make_pointer(){
    int local = 23; 
    return &local; 
}


int main () {
    int *p = make_pointer(); 
    std::cout << *p << std::endl; // ALTHOUGH THIS COMPILES, BUT IT RAISES WARNING : warning: address of stack memory associated with local variable 'local' returned 
    return 0; 
}


/* 
TO Tackle such issues of dangling pointer, RAII is proposed (Resource Acquisition Is Initialization)
*/