#include<bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        ll n = a.size() ;
        ll m = a[0].size(); 
        ll col1 = 1;
        ll row1 = 1;  
        for(ll i= 0 ; i < n ;i++ ) {
            for(ll j = 0 ; j < m ;j++ ) {
                if(a[i][j] == 0 ) {
                    a[0][j] = 0 ;
                    a[i][0] = 0 ;
                    if(i == 0  ) col1 = 0 ;
                    if(j == 0  ) row1 = 0 ; 
                }
            }
        }
        for(ll i =0  ;i < n; i++ ) {
            if(i == 0 ) continue; 
            if(a[i][0] == 0 ) {
                for(ll j= 0  ; j < m ; j++ ) a[i][j] = 0 ; 
            }
        }
        for(ll i =0  ;i < m; i++ ) {
            if(i == 0 ) continue;
            if(a[0][i] == 0 ) {
                for(ll j= 0  ; j < n ; j++ ) a[j][i] = 0 ; 
            }
        }
        if(col1 == 0 ) {
            for(ll i =0  ; i< m ;i++ ) a[0][i] = 0 ; 
           
        }
        if(row1 == 0 ) {
             for(ll i =0  ; i< n ;i++ ) a[i][0] = 0 ; 
        }
    }
};