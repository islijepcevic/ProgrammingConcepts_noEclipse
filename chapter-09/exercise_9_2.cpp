#include <iostream>

int func() throw();

int main() {

    double *px = NULL;
    
    try {
        px = new double[1000000000];

        delete px; // I WOULD PUT THE delete HERE
        
    } catch (std::bad_alloc& ex) {
        std::cout << "bad allocation\n";
    }

    //delete px; // not sure if this should go here or in the try block

    return 0;
}
