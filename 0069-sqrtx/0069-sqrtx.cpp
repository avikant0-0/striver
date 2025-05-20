class Solution {
public:
    int mySqrt(int x) {
        long long l = 0, r = 1e9;
        while(l <= r){
            long long  mid = r - (r-l) / 2 ;
            if(mid * mid < x) l = mid + 1;
            else r = mid - 1;
        }
        if((r+1)*(r+1) == x) return (r+1);
        else return r;
    }
};