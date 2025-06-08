class Solution {
public:
    void sieve(auto& isPrime)
    {
        int n = isPrime.size();
        for(int i = 2; i < n; i++)
        {
            if(isPrime[i] == 0) continue;
            for(int j = 2; j <= n; j++)
            {   
                if(j*i >= n) break;
                isPrime[j*i] = 0;
            }
        }
    }
    int countPrimes(int n) 
    {   
        vector<int> isPrime(n+1,1);
        sieve(isPrime);

        int cnt = 0;
        for(int i = 2; i < n; i++)
            if(isPrime[i]) {
                cnt++;
            }

        return cnt;
    }
};