#include<iostream>

using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

/*
    1] For loop i from 0 to n - 1
    2] For loop j from 1 to n - i - 1
    3] Swap element at j with element at j + 1 if element at j is greater than that of j + 1
*/
void bubbleSort(int arr[], int n) {
    int temp;
    bool sorted = true;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                sorted = false;
            }
        }
        if (sorted) return;
    }
    
}

int main() {
    int arr[] = {3, 2, 1, 5, 4, 6, 0};
    int n = 7;
    printArray(arr, n);
    bubbleSort(arr, n);
    printArray(arr, n);
    return 0;
}
