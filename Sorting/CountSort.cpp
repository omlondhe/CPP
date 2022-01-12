#include<iostream>
#include<stdlib.h>
#include<limits.h>

using namespace std;

void printArray(int arr[], int l) {
    for (int i = 0; i < l; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int getMax(int arr[], int n) {
    int max = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (max <arr[i]) max =arr[i];
    }
    return max;
}

void countSort(int arr[], int l) {
    int i, j;
    int max = getMax(arr, l);
    int* count = (int*)malloc((max + 1) * sizeof(int));

    for (i = 0; i <= max; i++) {
        count[i] = 0;
    }

    for (i = 0; i < l; i++) {
        count[arr[i]] = count[arr[i]] + 1;
    }

    i = 0; 
    j = 0;

    while (i <= max) {
        if (count[i] > 0) {
            arr[j] = i;
            count[i]--;
            j++;
        } else {
            i++;
        }
    }
}

int main() {
    int arr[] = {3, 2, 5, 4, 1, 0};
    int l = 6;

    printArray(arr, l);
    countSort(arr, l);
    printArray(arr, l);

    return 0;
}
