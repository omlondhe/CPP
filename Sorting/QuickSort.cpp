#include<iostream>

using namespace std;

void printArray(int arr[], int l) {
    for (int i = 0; i < l; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    do {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }

        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while(i < j);

    arr[low] = arr[j];
    arr[j] = pivot;

    return j;
}

void quickSort(int arr[], int low, int high) {
    int partitionIndex;

    if (low >= high) return;

    partitionIndex = partition(arr, low, high);
    quickSort(arr, low, partitionIndex - 1);
    quickSort(arr, partitionIndex + 1, high);
}

int main() {
    int arr[] = {4, 3, 6, 7, 1, 0, 2, 9, 5, 8};

    printArray(arr, 10);
    quickSort(arr, 0, 9);
    printArray(arr, 10);

    return 0;
}
