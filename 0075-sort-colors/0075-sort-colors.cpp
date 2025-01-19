class Solution {
public:
    void sortColors(vector<int>& nums){
	int n = nums.size();
	int low = 0, mid = 0,high = n - 1 ; 
	
	while(mid <= high){
		if(nums[mid] == 1){
 		mid++;
                        continue;
		}
	else if(nums[mid] == 0){
		swap(nums[mid],nums[low]);
		low++; 
        mid++; 
	}
	else if(nums[mid] == 2){
		while(high - 1 > mid && nums[high-1] == 2 && nums[high] == 2) high -= 1; 
       
        swap(nums[mid],nums[high]); 
        high -= 1; 
	}
	}
}

};