class Solution {
public:
    int majorityElement(vector<int>& a) {
        int cnt = 0;
        int ele = -1;
        for(int i = 0; i < a.size(); i++){
            if(cnt == 0) ele = a[i];
            if(ele == a[i]) ++cnt;
            else --cnt;
        }
        return ele;
    }
};