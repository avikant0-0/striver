class Solution {
public:
    int divide(long long dividend, long long divisor) {
        if(dividend == divisor) return 1;
        if(dividend == -divisor) return -1;
        int sign = 1;
        if(dividend < 0) sign = sign * -1;
        if(divisor  < 0) sign = sign * -1;
        long long ans = 0;

        dividend = abs(dividend);
        divisor = abs(divisor);

        while(dividend >= divisor)
        {   
            int i = 0;
            while((divisor << (i+1)) < dividend) ++i;


            dividend -= (divisor << i);
            ans = ans + (1<<(i));

            if(ans * sign <= INT_MIN) return INT_MIN;
            if(ans * sign >= INT_MAX) return INT_MAX;
        }

        return ans*sign;
    }
};