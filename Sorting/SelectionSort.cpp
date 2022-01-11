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
    2] Get the minimum element from range (i + 1) to n
    3] Replace it with the current pass element
*/
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            min = (arr[min] > arr[j]) ? j : min;
        }
        int temp = arr[i]; 
        arr[i] = arr[min];
        arr[min] = temp;
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
