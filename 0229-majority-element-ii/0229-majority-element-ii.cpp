class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
        int ele1=INT_MIN,cnt1=0,ele2=INT_MIN,cnt2=0;
        for(int i = 0; i < a.size(); i++){
            if(cnt1 == 0 && a[i] != ele2){
                ele1 = a[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0 && a[i] != ele1){
                ele2 = a[i];
                cnt2 = 1;
            }
            else if(a[i] == ele1){
                ++cnt1;
            }
            else if(a[i] == ele2){
                ++cnt2;
            }
            else --cnt1,--cnt2;
        }
        vector<int> ans;
        cnt1 = 0, cnt2 = 0;
        for(int  i = 0; i < a.size(); i++){
            if(a[i] == ele1) cnt1++;
            else if(a[i] == ele2) cnt2++;
        }
        if(ele1!=INT_MIN && cnt1 > a.size()/3) ans.push_back(ele1);
        if(ele2!=INT_MIN && cnt2 > a.size()/3) ans.push_back(ele2);
        return ans;
    }
};