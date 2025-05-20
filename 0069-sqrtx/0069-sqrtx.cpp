class Solution {
public:
    int mySqrt(int x) {
        if(!x) return x;
        int l = 1, r = 1e9;
        while(l <= r){
            int  mid = r - (r-l) / 2 ;
            if(mid <= x / mid) l = mid + 1;
            else r = mid - 1;
        }
        return r;
    }
};