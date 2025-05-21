class Solution {
public:
    int splitArray(vector<int>& a, int k) {
        int n = a.size(), l = 0, r = 1e9;

        while(l <= r){
            int mid = midpoint(l,r);
            int s = 0, sum = 0;
            for(int i = 0; i < n; i++){
                if(a[i] > mid){
                    s = k + 1;
                    break;
                }
                if(sum + a[i] > mid){
                    sum = a[i];
                    s++;
                }else if(sum + a[i] == mid){
                    sum = 0;
                    s++;
                }else{
                    sum += a[i];
                }
            }

            if(sum != 0 && sum <= mid) ++s;

            if(s > k) l = mid + 1;
            else r = mid - 1;
        }
        return r+1;
    }
};