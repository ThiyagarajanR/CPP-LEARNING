#include<iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <thread>

int main()
{
    int stackArray[] = {1, 2, 3, 4, 5}; // Stack memory allocation
     std::unique_ptr<int[]> heapArray (new  int[5]{6, 7, 8, 9, 10}); // Heap memory allocation
    std::cout<< "Stack Array Address : "  << std::endl;
    for (auto i : stackArray)
    {
        std::cout<< "Stack Array Element : " << i << " and Address : "<< &i <<std::endl;
    }

    std::cout<< "Heap Array Address : "  << std::endl;

    for (auto i = 0; i < 5; ++i)
    {
        std::cout<< "Heap Array Element : " << heapArray[i] << " and Address : "<< &heapArray[i] <<std::endl;
    }

    // TODO: Your task

    // 1. Print "Loading..." (no newLine)
    // 2. Add dots one by one: . . . .
    // 3 .Make each dot appear immediately (use std::flush)
    // 4. wait 500ms between each dot
    // 5. Also save progress to a file "progress.log"
    // 6. Flush the file after each dot too
    std::cout << "Loading";
    std::ofstream progressFile("progress.log");
    if (!progressFile) {
        std::cerr << "Error opening file for writing." << std::endl;
        return 1;
    }
    for (int i = 0; i < 5; ++i) {
        std::cout << ".";
        progressFile << ".";
        std::cout.flush();
        progressFile.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    progressFile.close();

    return 0;;

}