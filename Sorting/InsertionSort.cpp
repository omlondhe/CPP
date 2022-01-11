#include<iostream>

using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

/*
    1] For loop i from 1 to n
    2] Take two variables
    3] key, to check element with and j to check it with the set targeted by it
    4] in for loop i, initialize key with current element at index i 
    5] j with i - 1
    6] loop till j th element of array is greater than key and j is greater than equal to 0
    7] give the value of (j + 1)th element to j th element for each of the above satisfying case 
    8] When while loop ends, give the value of the key to the (j + 1)th index
*/
void insertionSort(int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (arr[j] > key && j >= 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {3, 2, 1, 5, 4, 6, 0};
    int n = 7;
    printArray(arr, n);
    insertionSort(arr, n);
    printArray(arr, n);
    return 0;
}
