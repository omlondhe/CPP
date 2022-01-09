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

    const int N = 1000;
    int idx[N];
    for (int i = 0; i < N; i++)
    {
        idx[i] = -1;
    }

    int minimumIndex = __INT_MAX__;
    
    for (int i = 0; i < n; i++)
    {
        if (idx[a[i]] != -1) {
            minimumIndex = min(minimumIndex, idx[a[i]]);
        } else {
            idx[a[i]] = i;
        }
    }
    
    if(minimumIndex == __INT_MAX__) {
        cout<<"-1"<<endl;
    } else {
        cout<<minimumIndex + 1<<endl;
    }

    return 0;
}

