#include <iostream>
#include <algorithm>
#include <fstream>

int* merge(int* left, int leftLen, int* right, int rightLen, int pivot, int pivotCount) {
    int totalLen = leftLen + pivotCount + rightLen;
    int* merged = new int[totalLen];
    int index = 0;

    for (int i = 0; i < leftLen; i++) {
        merged[index++] = left[i];
    }
    for (int i = 0; i < pivotCount; i++) {
        merged[index++] = pivot;
    }
    for (int i = 0; i < rightLen; i++) {
        merged[index++] = right[i];
    }

    return merged;
}

int* quick_sort(int* arr, int len) {
    if (len <= 1) {
        int* base = new int[len];
        if (len == 1)
            base[0] = arr[0];
        return base;
    }

    // middle element pivot
    int pivot = arr[len / 2];


    int leftCount = 0, rightCount = 0, pivotCount = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] < pivot)
            leftCount++;
        else if (arr[i] > pivot)
            rightCount++;
        else
            pivotCount++;
    }

    int* leftArr = new int[leftCount];
    int* rightArr = new int[rightCount];

    int l = 0, r = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] < pivot)
            leftArr[l++] = arr[i];
        else if (arr[i] > pivot)
            rightArr[r++] = arr[i];
    }

    int* sortedLeft = quick_sort(leftArr, leftCount);
    int* sortedRight = quick_sort(rightArr, rightCount);
    int* sortedArr = merge(sortedLeft, leftCount, sortedRight, rightCount, pivot, pivotCount);

    delete[] leftArr;
    delete[] rightArr;
    delete[] sortedLeft;
    delete[] sortedRight;
    return sortedArr;
}

int main()
{
    std::ifstream inputFile("input.txt");
    std::ofstream outFile("output_qs.txt");

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

    int* sortedArr = quick_sort(arr, n);
 
    outFile << "Output: ";
    for (int i = 0; i < n; i++) {
        outFile << sortedArr[i] << " ";
    }
    outFile << std::endl;

    outFile.close();
    delete[] sortedArr;
}

