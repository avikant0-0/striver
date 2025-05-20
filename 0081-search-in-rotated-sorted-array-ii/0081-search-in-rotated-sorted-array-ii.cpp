class Solution {
public:
    bool search(vector<int>& a, int t) {
        int n = a.size();
        int l = 0,r = n-1;
        while(l <= r){
            int mid = (r+l)/2;
            if(a[mid] == t) return true;

            if(a[mid] == a[l] && a[mid] == a[r]) {
                ++l,--r;
                continue;
            }

            if(a[l] <= a[mid]){
                if(t>=a[l]&&t<=a[mid]){
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }else{
                if(t>=a[mid]&&t<=a[n-1]){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
        }
        return 0;
    }
};