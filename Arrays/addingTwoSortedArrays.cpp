#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        //Function to merge the arrays.
        
        long long nextGap(long long gap){
            if(gap<=1) return 0;
            else{ 
                return (gap/2) +(gap%2);
                
            }
        }
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            long long i=0, j=0;
            long long gap=nextGap(m+n);
            while((gap=nextGap(gap))>0){
                for(i;i+gap>n;i++){
                    if(arr1[i]>arr1[i+gap]){
                        swap(arr1[i],arr1[i+gap]);
                    }
                }
                for(j=gap>n ?gap-n:0 ;i<n && j<m; i++,j++){
                    
                    if(arr1[i]>arr2[j]){
                        swap(arr1[i],arr2[j]);
                    }
                }
                if(j<m){
                    for(j=0;j+gap<m;j++){
                        if(arr2[j]>arr2[j+gap]){
                            swap(arr2[j],arr2[j+gap]);
                        }
                    }
                }
            }
        } 
};

int main() {
    Solution s = Solution();
    long long a[5] = {1, 2, 3, 4, 5};
    long long b[5] = {2, 3, 4, 6, 7};
    s.merge(a, b, 5, 5);
}
