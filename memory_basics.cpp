#include <iostream>
#include <string>
using namespace std;

void demonstrateStack() {
    cout << "=== STACK OBJECTS ===" << endl;
    
    // These objects live on the STACK
    int number = 42;                    // Simple variable on stack
    string message = "Hello Stack";     // String object on stack
    
    cout << "number: " << number << endl;
    cout << "message: " << message << endl;
    cout << "Address of number: " << &number << endl;
    cout << "Address of message: " << &message << endl;
    
    // When this function ends, number and message are 
    // AUTOMATICALLY destroyed (destructors called)
    cout << "Function ending - stack objects will be cleaned up automatically" << endl;
}

void demonstrateHeap() {
    cout << "\n=== HEAP OBJECTS ===" << endl;
    
    // These objects live on the HEAP
    int* pNumber = new int(99);         // Integer on heap
    string* pMessage = new string("Hello Heap");  // String on heap
    
    cout << "pNumber points to: " << *pNumber << endl;
    cout << "pMessage points to: " << *pMessage << endl;
    cout << "Address pNumber points to: " << pNumber << endl;
    cout << "Address pMessage points to: " << pMessage << endl;
    
    // CRITICAL: You must manually delete heap objects
    delete pNumber;     // Free the integer
    delete pMessage;    // Free the string
    
    // After delete, the pointers still hold the addresses
    // but the memory is no longer valid (dangling pointers!)
    cout << "Objects deleted - memory freed" << endl;
}

void demonstrateMFCPattern() {
    cout << "\n=== MFC-STYLE PATTERN ===" << endl;
    
    // This is similar to what you see in MFC
    string localString = "I'm on stack";           // Like CString str = "text";
    string* pDynamicString = new string("I'm on heap"); // Like CButton* pBtn = new CButton();
    
    cout << "Local string: " << localString << endl;
    cout << "Dynamic string: " << *pDynamicString << endl;
    
    // localString will be cleaned up automatically when function ends
    // pDynamicString MUST be manually deleted
    delete pDynamicString;
}

int main() {
    cout << "C++ Memory Model Demonstration" << endl;
    cout << "================================" << endl;
    
    demonstrateStack();
    demonstrateHeap();
    demonstrateMFCPattern();
    
    cout << "\nProgram ending - all stack objects in main() will be cleaned up" << endl;
    return 0;
}