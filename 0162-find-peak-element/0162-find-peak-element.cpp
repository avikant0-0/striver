class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int n = a.size();
        int l = 0, r = n - 1;
        while(l <= r){
            int mid = midpoint(l,r);
            long long left = (mid-1>=0?a[mid-1] : -1e15);
            long long right = (mid+1 < n ? a[mid+1] : -1e15);

            if(a[mid]>left && a[mid] > right) return mid;
            if(a[mid] <= right) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
};