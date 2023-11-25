#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <ctime>

int partition(std::vector<int>& array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (array[j] < pivot) {
            i++;
            std::swap(array[i], array[j]);
        }
    }

    std::swap(array[i + 1], array[high]);

    return i + 1;
}


void quickSort(std::vector<int>&array, int low, int high){
    if(low < high){
        int pivotIndex = partition(array, low , high);

        quickSort(array, low, pivotIndex -1);
        quickSort(array, pivotIndex + 1, high);
    }
}



int binarySearch(std::vector<int>&array, int target){

int left = 0;
int right = array.size() - 1;

    while(left <= right){
    int mid = left + (right - left) / 2;


        if(array[mid] == target){
        return mid;
        }
        else if(array[mid] < target){
        left = mid + 1;
        }
        else {
        right = mid -1;
        }
    }
return -1;
}

int main(){

const int arraySize = 77;
std::vector<int> nonSortedArray;

std::srand(std::time(0));

for(int i = 0; i < arraySize; ++i){
    nonSortedArray.push_back(std::rand() % 100);
}

 std::cout << "Generated non-sorted array: ";
    for (int i = 0; i < arraySize; ++i) {
        std::cout << nonSortedArray[i] << ", ";
    }

std::cout << std::endl;
std::cout << std::endl;
std::cout << std::endl;

quickSort(nonSortedArray, 0, arraySize - 1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < arraySize; ++i) {
        std::cout << nonSortedArray[i] << ", ";
    }    
std::vector<int> sortedArray = nonSortedArray;


std::cout << std::endl;
std::cout << std::endl;
std::cout << std::endl;

int target = 11;

int result = binarySearch(sortedArray, target);

if(result != -1){
    std::cout << "Element found at index " << result<< std::endl;
}
else {
    std::cout << "Element not found within array" << std::endl;
}

std::cout << std::endl;
std::cout << std::endl;

    
    
    return 0;
}













