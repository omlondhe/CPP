#include<iostream>
using namespace std;

int main() {
    int n, reverse;

    cin>>n;

    while (n > 0)
    {
        int lastDigit = n % 10;
        reverse = reverse * 10 + lastDigit;
        n /= 10;
    }

    cout<<"Reverse is: "<<reverse;
    

    return 0;
}
