#include <iostream>

struct point
{
    char c;
    int a;
    int b;
};

// The magic of re-ordering
struct A
{
    char a;
    int b;
    char c;
};

struct B
{
    int b;
    char a;
    char c;
};

int main()
{
    std::cout << "size of struct point: " << sizeof(point) << std::endl;
    /*
        It outputs 12, while-
            1. char : 1
            2. int : 4
        So, technically it should be 9 bytes and not 12

        - A 4-byte int commonly needs to begin at an address divisible by 4. The compiler may insert    unused bytes called padding between members and at the end of the struct.
    */
    std::cout << "size of struct A: " << sizeof(A) << "\n"
              << "size of struct B: " << sizeof(B) << std::endl;
          
    return 0;
}