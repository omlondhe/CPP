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
    
    const int N = 1e6 + 2;
    bool check[N];

    for (int i = 0; i < n; i++)
    {
        check[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
        {
            check[a[i]] = true;
        }
    }
    
    int answer = -1;
    for (int i = 1; i < N; i++)
    {
        if (check[i] == false) {
            answer = i;
            break;
        }
    }
        
    cout<<answer<<endl;

    return 0;
}
