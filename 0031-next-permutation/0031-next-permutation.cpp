class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n = a.size();
        int flag = false;
        for(int i = n - 1; i >= 1; i--){
            if(a[i-1]<a[i]){
                flag = 1;
                int mx ;
                for(int j = n - 1; j >= i; j--){
                    if(a[j]>a[i-1]) {
                        mx = j; 
                        break;
                    }
                }
                swap(a[mx],a[i-1]);
                reverse(a.begin()+i,a.end());
                break;
            }
        }
        if(!flag) reverse(a.begin(),a.end());
    }
};