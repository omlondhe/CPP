#include<iostream>

using namespace std;

int main() {
    int arr[] = {-1, 111, 0, 13, 14, -10, 16, 17, 18, 9};
    int l = 10;

    int smallest = INT8_MAX, secondSmallest = INT8_MAX;

    for (int i = 0; i < l; i++) {
        if (arr[i] < smallest) smallest = arr[i];
        if (smallest < arr[i] && arr[i] < secondSmallest) secondSmallest = arr[i];
    }

    cout << "Smallest: " << smallest << "\n";
    cout << "Second Smallest: " << secondSmallest << "\n";

    return 0;
}
