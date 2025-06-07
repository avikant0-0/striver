class Solution {
public:
    int divide(long long dividend, long long divisor) {
        long long q = dividend / divisor;
        if(q >= INT_MAX) return INT_MAX;
        else if(q <= INT_MIN) return INT_MIN;
        return dividend / divisor;
    }
};