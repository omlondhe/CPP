#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int n, sum;

    cin>>n;

    int original = n;

    while (n > 0)
    {
        int lastDigit = n % 10;
        sum += pow(lastDigit, 3);
        n /= 10;
    }    

    sum == original ? cout<<original<<" is Armstrong Number" : cout<<original<<" is not Armstrong Number";

    return 0;
}
