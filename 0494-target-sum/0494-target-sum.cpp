class Solution {
public:
    
int findWays(vector<int>& a, int k)
{	
	int n = a.size();
	vector<int> up(k+1,0);

	up[0] = 1;
	
	
	for(int i = 1; i <= n; i++)
	{	
		vector<int> temp(k+1,0);
		for(int j = 0; j <= k; j++)
		{
			int nottake = up[j];
			int take = 0;
			if(a[i-1] <= j)
				take = up[j-a[i-1]];
			
			temp[j] = (take + nottake);
		}
		up = temp;
	}
	return up[k];
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int tsum = accumulate(nums.begin(),nums.end(),0);
        int tofind = (tsum + target) / 2;

        if( (tsum + target) % 2 != 0 || tofind < 0) return 0;
        
        return findWays(nums,tofind);
    }
};