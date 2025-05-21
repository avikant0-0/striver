class Solution {
public:
    int smallestDivisor(vector<int>& a, int t) {
        int l = 1 , r  = 1e7;
        while( l <= r){
            int mid = midpoint(l,r);
            int currval = 0;
            for(int i = 0; i < a.size(); i++){
                currval +=  (a[i]+mid-1)/mid;
            }
            if( currval <= t ) r = mid - 1;
            else l = mid + 1;
        }
        return r + 1;
    }
};