class Solution {
public:
    double f(double x,long n){
        if(n == 0) return 1;    
        // if(n == 1) return x;

        if(n % 2 == 0) return f(x*x,n/2);
        else return x * f(x,n-1);
    }
    double myPow(double x, int n) {
        if( !x ) return x;

        long long N = n;

        if( n < 0 ){
            N = -N;
            x =  1 / x;
        }

        return f(x,N);
    }
};