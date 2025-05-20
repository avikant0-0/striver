class Solution {
public:
    int minEatingSpeed(vector<int>& a, int h) {
       long long l = 1, r = 1e9;
       long long n = a.size();
       while(l <= r){
        long long mid = midpoint(l,r);

        long long req_hr = 0;
        long long flag = 0;
        for(long long i = 0; i < n;i++){
            long long add = ((a[i]+mid-1)/mid);
            // if(req_hr >= INT_MAX - add){
            //     flag = 1;
            //     break;
            // }
            req_hr += add;
        }
        if(flag){
            r = mid - 1;
            continue;
        }
        if(req_hr > h) l = mid + 1;
        else r = mid - 1;
       }

       return r+1;
    }
};