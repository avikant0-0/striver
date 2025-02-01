class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int P = 0;
        int S = 0;
       

        int ans = 0;

        int i = 0, j = n - 1; 

        while(i <= j){
            if(height[i] <= height[j]){
                int curr = P - height[i];
                if(curr>0){
                    ans += curr;
                }
                P = max(P,height[i]);
                ++i;
            }else{
                int curr = S - height[j];
                if(curr>0){
                    ans += curr;
                }
                S = max(S,height[j]);
                --j;
            }
        }
        
        return ans ;
    }
};