class Solution {
public:
    vector<int> memo;
    bool f(int i,auto& a){
        if(i >= a.size() - 1) return true;
        if(memo[i] != -1) return memo[i];

        for(int jump = 1; jump <= a[i]; jump++){
            if(f(i+jump,a)){
                return memo[i] = true;
            }
        }
        return memo[i] = false;
    }
    bool canJump(vector<int>& a) {
        int n = a.size();
        memo.assign(n, -1);
        return f(0,a);
    }
};