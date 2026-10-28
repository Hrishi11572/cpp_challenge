#include <iostream>
#include <thread>

void task(int id) {
    std::cout << "Started task " <<  id << std::endl; 
    std::cout << "Finished task " <<  id << std::endl; 
}

// int main () {
//     std::cout << "Start of the program" << std::endl; 
    
//     task(1); 
//     task(2); 
//     task(3); 
//     task(4); 

//     std::cout << "End of program" << std::endl; 
//     return 0; 
// }

// Concurrent Program 
int main () {
    std::cout << "Start of the program" << std::endl; 
    
    std::thread t1(task, 1); 
    std::thread t2(task, 2); 
    std::thread t3(task, 3); 
    std::thread t4(task, 4); 

    t1.join();
    
    std::cout << "join t1 was hit" << std::endl; 
    
    t2.join();

    std::cout << "join t2 was hit" << std::endl; 

    t3.join(); 

    std::cout << "join t3 was hit" << std::endl; 

    t4.join();

    std::cout << "join t4 was hit" << std::endl; 
    
    return 0; 
}