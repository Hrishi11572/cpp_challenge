/*
A lambda is essentially a compiler-generated function object (functor).

The compiler creates an unnamed class with an overloaded operator().

If the lambda captures variables, the compiler-generated object stores those captured values as members.
*/

#include<iostream>
using namespace std; 


int main() {
    int x = 10; 

    auto func = [x] () mutable {
        ++x; 
        cout << x << "\n"; 
    }; 

    func();

    cout << "x : " << x << endl; // original variable are not changed, as passed by value. 
    return 0; 
}

/*
Mutability Issues: 

int x = 10;

    auto func = [x]() {
        x++;
    };

    func();

the code above does not compile. 

Remember the compiler-generated functor we discussed?
Its operator() is const by default for a normal lambda.

so we can not modify the internal state, which in this case is the value x. 
*/