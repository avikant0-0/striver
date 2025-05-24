class Solution {
public:
    int f(vector<int>& a,int k)
{   
    if(k<0) return 0;
    int i = 0, j = 0, ans = 0;
    vector<int> hash(a.size()+1);
    int d = 0;

    while( j < a.size() ){
        if(hash[a[j]] == 0) d++;
        hash[a[j]]++;

        while(d > k){
            hash[a[i]]--;
            if(hash[a[i]] == 0) --d;
            ++i;
        }

        ans += j - i + 1;
        j++;
    }

    return ans;
}

    int subarraysWithKDistinct(vector<int>& a, int k) {
        return f(a,k) - f(a,k-1);
    }
};