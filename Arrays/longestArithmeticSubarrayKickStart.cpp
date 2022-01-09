#include<iostream>
using namespace std;

int main() {
    int n;

    cin>>n;

    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    int answer = 2;
    int previousDifference = a[1] - a[0];
    int j = 2;
    int currentLength = 2;

    while (j < n)
    {
        if (previousDifference == a[j] - a[j - 1]) {
            currentLength++;
        } else {
            previousDifference = a[j] - a[j - 1];
            currentLength = 2;
        }

        answer = max(answer, currentLength);
        j++;
    }
    
    
    cout<<answer<<endl;
    return 0;
}
