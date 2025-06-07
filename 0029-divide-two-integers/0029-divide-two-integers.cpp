class Solution {
public:
    int divide(long long dividend, long long divisor) {
        int sign = 1;
        if(dividend < 0) sign = sign * -1;
        if(divisor  < 0) sign = sign * -1;
        long  ans = 0;

        dividend = abs(dividend);
        divisor = abs(divisor);

        while(dividend >= divisor)
        {   
            int i = 0;
            while((divisor<<(i+1)) < dividend) 
            {
                // cout << (divisor<<(i+1)) << " " << i  << endl;
                ++i;
            }


            dividend -= divisor << (i);
            ans += 1<<i;

            if(ans * sign <= INT_MIN) return INT_MIN;
            if(ans * sign >= INT_MAX) return INT_MAX;
        }

        return ans*sign;
    }
};