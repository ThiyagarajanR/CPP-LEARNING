#include <iostream>
#include <string>
using namespace std;

int main() {
    // Stack variables
    int stackInt = 42;
    string stackString = "Stack String";
    
    // Heap variables
    int* heapInt = new int(99);
    string* heapString = new string("Heap String");
    
    // Array on stack
    int stackArray[5] = {1, 2, 3, 4, 5};
    
    // Array on heap
    int* heapArray = new int[5]{10, 20, 30, 40, 50};
    
    // Set breakpoint here (click on line number)
    cout << "=== BREAKPOINT HERE ===" << endl;
    
    cout << "Stack int: " << stackInt << " at address: " << &stackInt << endl;
    cout << "Heap int: " << *heapInt << " at address: " << heapInt << endl;
    
    cout << "Stack string: " << stackString << " at address: " << &stackString << endl;
    cout << "Heap string: " << *heapString << " at address: " << heapString << endl;
    
    cout << "Stack array[0]: " << stackArray[0] << " at address: " << &stackArray[0] << endl;
    cout << "Heap array[0]: " << heapArray[0] << " at address: " << &heapArray[0] << endl;
    
    // Cleanup heap memory
    delete heapInt;
    delete heapString;
    delete[] heapArray;
    
    return 0;
}