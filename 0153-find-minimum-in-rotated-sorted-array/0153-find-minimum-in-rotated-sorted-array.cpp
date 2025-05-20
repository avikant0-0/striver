class Solution {
public:
    int findMin(vector<int>& a) {
        int n = a.size();
        int l = 0, r = n - 1;
        while(l <= r){
            int mid = midpoint(l,r);
            cout << mid << endl;
            if(a[mid]>a[n-1]){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        // cout << r << endl;
        return r < 0 ? a[0] : a[r+1];
    }
};