#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverse(int x) {
       int ans = 0;

       while(x != 0){
        int digit = x % 10;
        
        if(digit < 0){
            if(ans <( INT_MIN - digit)/10)  return 0;
        }
        else{
            if(ans > (INT_MAX - digit)/10) return 0;
        }
        ans = 10*ans + digit;
        x/=10;
       }
       return ans;
    }
};