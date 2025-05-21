class Solution {
public:
    int shipWithinDays(vector<int>& a, int days) {
        int l = 1, r = 1e9;
        while( l <= r ){
            int mid = midpoint(l,r);
            int days_req = 0;
            int wt = 0;
            for(int i = 0; i < a.size(); i++){
                if(a[i] > mid){
                    days_req = days + 1;
                    break;
                }
                if(wt + a[i] < mid){
                    wt += a[i];
                }else if(wt + a[i] == mid){
                    wt = 0;
                    ++days_req; 
                }else{
                    wt = a[i];
                    ++days_req;
                }
            }
            if(wt != 0 && wt < mid) ++days_req;
            // cout << mid <<" " << days_req << endl;
            if(days_req>days) l = mid + 1;
            else r = mid - 1;
        }
        return r + 1;
    }
};