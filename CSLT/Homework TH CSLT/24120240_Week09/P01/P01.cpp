#include <iostream>  

void addOne(int* ptrNum) {
    (*ptrNum)++;
}

int main() {
    int myNum = 5;  
    std::cout << "Initial value: " << myNum << std::endl;  
    addOne(&myNum);
    std::cout << "Value after addOne: " << myNum << std::endl;

    return 0;
}