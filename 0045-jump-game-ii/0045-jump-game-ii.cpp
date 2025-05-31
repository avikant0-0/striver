class Solution {
public:
    int jump(vector<int>& a) {
        int n = a.size();
        int l = 0, r = 0, jumps = 0;
        while(r < n - 1){
            int mx = 0;
            for(int i = l; i <= r; i++){
                mx = max(mx,i+a[i]);
            }
            l = r + 1;
            r = mx;
            jumps += 1;
        }
        return jumps;
    }
};