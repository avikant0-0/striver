#include<bits/stdc++.h>
class Solution {
public:
    int search(vector<int>& a, int t) {
        int n = a.size();
        int l = -1,r = n;
        while( r - l > 1 ){
            int mid = (r+l)/2;
            if(a[mid]>a[n-1]) l = mid;
            else r = mid;
        }

        if(r <= n - 1){
            int ind;
            if(r - 1 >= 0 && t>=a[0]&&t<=a[r-1]){
                ind = lower_bound(a.begin(),a.begin()+r,t)-a.begin(); 
                
            }else{
                ind = lower_bound(a.begin()+r,a.end(),t)-a.begin();
            }
            if (ind < n &&  a[ind] == t )  return ind;
            else return -1;
        }else{
            int ind = lower_bound(a.begin(),a.begin()+r,t)-a.begin(); 
            if ( ind < n && a[ind] == t )  return ind;
            else return -1;
        }

        return -1;
    }   
};