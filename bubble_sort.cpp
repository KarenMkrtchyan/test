#include <iostream>
#include <algorithm>
#include <fstream>

void bubble_sort(int* arr, int len) {
    bool made_swap = false;
    int temp;
    if (len > 1) {
        for (int i = 0; i < len-1; i++) {
            if (arr[i + 1] < arr[i]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                made_swap = true;
            }
        }
    }
    if (made_swap) {
        bubble_sort(arr, len); // loop again until its sorted
    }
}

int main()
{
    std::ifstream inputFile("input.txt");
    std::ofstream outFile("output_bubble.txt");

    if (!inputFile)
    {
        std::cerr << "Unable to open file" << std::endl;
        return 1;
    }

    int n;
    inputFile >> n;

    int* arr = new int[n];
    outFile << "Input: ";

    for (int i = 0; i < n; ++i)
    {
        inputFile >> arr[i];
        outFile << arr[i] << " ";
    }
    outFile << "\n";

    int target;
    inputFile >> target;

    inputFile.close();

    int* sortedArr = bubble_sort(arr, n);
 
    outFile << "Output: ";
    for (int i = 0; i < n; i++) {
        outFile << sortedArr[i] << " ";
    }
    outFile << std::endl;

    outFile.close();
    delete[] sortedArr;
}

