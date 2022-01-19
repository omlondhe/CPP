#include<iostream>

using namespace std;


void merge(int arr[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low, mergedArr[high + 1];

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) mergedArr[k++] = arr[i++];
        else mergedArr[k++] = arr[j++];
    }

    while (i <= mid) mergedArr[k++] = arr[i++];
    while (j <= high) mergedArr[k++] = arr[j++];

    for (int i = low; i <= high; i++) {
        arr[i] = mergedArr[i];
    }
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int arr[] = {5, 2, 4, 1, 3};
    printArray(arr, 5);
    mergeSort(arr, 0, 4);
    printArray(arr, 5);
}
