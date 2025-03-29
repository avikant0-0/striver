class Solution {
public:
    int b_s(int l,int r,auto& a,int target){
        --l,++r;
        while(r-l>1){
            int mid = ( r + l ) / 2;
            if(a[mid] < target) l = mid;
            else r = mid;
        }

        if(r == a.size()) return -1;
        if(a[r] == target) return r;
        else return -1;
    }
    int search(vector<int>& a, int target) {
        int n = a.size();
        int l = -1, r = n;
        int pv = -1;
        while(r - l > 1){
            int mid = ( r+l )/ 2;
            if(a[mid]>a[n-1]) l = mid;
            else r = mid;
        }
        pv = r;
        
        if(pv == 0){
            return b_s(0,n-1,a,target);
        }
        if( target >= a[0] && target <= a[pv-1] ){
            return b_s(0,pv-1,a,target);
        }else return b_s(pv,n-1,a,target);
    }
};