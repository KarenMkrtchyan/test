#include <iostream>
#include <algorithm>
#include <fstream>

int* merge(int* left, int leftLen, int* right, int rightLen) {
    int* merged = new int[leftLen+ rightLen];
    int* ptr1 = left; 
    int* ptr2 = right;
    int i = 0, j = 0, k = 0;
    while (i < leftLen && j < rightLen) {
        if (left[i] < right[j]) {
            merged[k++] = left[i++];
        }
        else {
            merged[k++] = right[j++];
        }
    }
    while (i < leftLen) {
        merged[k++] = left[i++];
    }
    while (j < rightLen) {
        merged[k++] = right[j++];
    }

    return merged;
}

int* merge_sort(int* arr, int len) {
    if (len == 1) {
        int* singleElementArray = new int[1];
        singleElementArray[0] = arr[0];
        return singleElementArray;
    }

    int mid = len / 2;
    int* left = merge_sort(arr, mid);
    int* right = merge_sort(arr + mid, len - mid);

    return merge(left, mid, right, len - mid);
}

int main()
{
    std::ifstream inputFile("input.txt");
    std::ofstream outFile("output_ms.txt");

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

    int* sortedArr = merge_sort(arr, n);
 
    outFile << "Output: ";
    for (int i = 0; i < n; i++) {
        outFile << sortedArr[i] << " ";
    }
    outFile << std::endl;

    outFile.close();
    delete[] sortedArr;
}

