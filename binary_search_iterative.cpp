#include <iostream>
#include <algorithm>
#include <fstream>

int bin_search_itr(int* arr, int len, int target) {
    int index = len / 2;
    while (index != 1) {
        if (arr[index] == target) {
            return index;
        }
        if (arr[index] > target) {
            index /=2;
        }
        else {
            index = (len + index)/2;
        }
    }
    return -1;
}

int main()
{
    std::ifstream inputFile("input.txt");
    std::ofstream outFile("output_bs.txt");

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
    outFile << "\nTarget: ";

    int target;
    inputFile >> target;
    
    outFile << target << "\n";

    inputFile.close();
    std::sort(arr, arr + n);
    int outcome = bin_search_itr(arr, n, target);
    
    outFile << "Output: ";
    if(outcome == -1){
    outFile << "Not Found\n";
    } else{
   outFile << outcome << "\n";
   }

    outFile.close();
}
