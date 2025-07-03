#include <iostream>
#include <string>
using namespace std;

void basicPointerConcepts() {
    cout << "=== BASIC POINTER CONCEPTS ===" << endl;
    
    // Variable and its pointer
    int value = 42;
    int* ptr = &value;  // ptr stores the ADDRESS of value
    
    cout << "value: " << value << endl;
    cout << "Address of value (&value): " << &value << endl;
    cout << "ptr (what it stores): " << ptr << endl;
    cout << "Address of ptr itself (&ptr): " << &ptr << endl;
    cout << "What ptr points to (*ptr): " << *ptr << endl;
    
    // Changing value through pointer
    *ptr = 99;
    cout << "\nAfter *ptr = 99:" << endl;
    cout << "value: " << value << endl;  // value changed!
    cout << "*ptr: " << *ptr << endl;
    
    cout << "\nKey insight: ptr and &value are the SAME address!" << endl;
    cout << "ptr == &value: " << (ptr == &value ? "true" : "false") << endl;
}

void pointerArithmetic() {
    cout << "\n=== POINTER ARITHMETIC ===" << endl;
    
    int numbers[5] = {10, 20, 30, 40, 50};
    int* ptr = numbers;  // Points to first element
    
    cout << "Array elements:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "numbers[" << i << "] = " << numbers[i] 
             << " at address " << &numbers[i] << endl;
    }
    
    cout << "\nUsing pointer arithmetic:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "*(ptr + " << i << ") = " << *(ptr + i)
             << " at address " << (ptr + i) << endl;
    }
    
    cout << "\nNotice: ptr + 1 moves by sizeof(int) = " << sizeof(int) << " bytes" << endl;
    cout << "ptr: " << ptr << endl;
    cout << "ptr + 1: " << (ptr + 1) << endl;
    cout << "Difference: " << (char*)(ptr + 1) - (char*)ptr << " bytes" << endl;
}

void nullPointers() {
    cout << "\n=== NULL POINTERS ===" << endl;
    
    int* ptr1 = nullptr;    // Modern C++ way
    int* ptr2 = NULL;       // C way (still used in MFC)
    int* ptr3 = 0;          // Also valid
    
    cout << "ptr1 (nullptr): " << ptr1 << endl;
    cout << "ptr2 (NULL): " << ptr2 << endl;
    cout << "ptr3 (0): " << ptr3 << endl;
    
    // Always check before dereferencing!
    if (ptr1 != nullptr) {
        cout << "*ptr1: " << *ptr1 << endl;  // This would crash!
    } else {
        cout << "ptr1 is null - cannot dereference" << endl;
    }
    
    // This is what you see in MFC
    if (ptr2 != NULL) {
        cout << "ptr2 is valid" << endl;
    } else {
        cout << "ptr2 is NULL (MFC style check)" << endl;
    }
}

void mfcStylePointers() {
    cout << "\n=== MFC-STYLE POINTER PATTERNS ===" << endl;
    
    // Simulating CWnd* pattern
    string windowTitle = "My Window";
    string* pWnd = &windowTitle;  // Like CWnd* pWnd = GetWindow();
    
    if (pWnd != NULL) {  // MFC always uses NULL
        cout << "Window title: " << *pWnd << endl;
        
        // Common MFC pattern: modify through pointer
        *pWnd = "Modified Window Title";
        cout << "After modification: " << windowTitle << endl;
    }
    
    // Simulating GetParent() returning NULL
    string* pParent = nullptr;  // Like CWnd* pParent = GetParent();
    
    if (pParent != NULL) {
        cout << "Parent window: " << *pParent << endl;
    } else {
        cout << "No parent window (pParent is NULL)" << endl;
    }
}

void doublePointers() {
    cout << "\n=== DOUBLE POINTERS (Advanced) ===" << endl;
    
    int value = 100;
    int* ptr = &value;
    int** ptrToPtr = &ptr;  // Pointer to pointer
    
    cout << "value: " << value << endl;
    cout << "ptr points to: " << *ptr << endl;
    cout << "ptrToPtr points to ptr, which points to: " << **ptrToPtr << endl;
    
    cout << "\nAddresses:" << endl;
    cout << "&value: " << &value << endl;
    cout << "ptr: " << ptr << endl;
    cout << "&ptr: " << &ptr << endl;
    cout << "ptrToPtr: " << ptrToPtr << endl;
    
    // Changing value through double pointer
    **ptrToPtr = 200;
    cout << "\nAfter **ptrToPtr = 200:" << endl;
    cout << "value: " << value << endl;
}

int main() {
    cout << "Pointer Deep Dive - Understanding C++/MFC Patterns" << endl;
    cout << "=================================================" << endl;
    
    basicPointerConcepts();

    pointerArithmetic();
    nullPointers();
    mfcStylePointers();
    doublePointers();
    
    return 0;
}