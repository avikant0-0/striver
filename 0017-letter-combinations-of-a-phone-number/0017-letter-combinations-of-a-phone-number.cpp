class Solution {
public:
    map<int, vector<char>> mp;

    void f(int ind,auto& a,auto& ans,auto& temp){
        if(ind == a.size()){
            if(!temp.empty()) ans.push_back(temp);
            return;
        }

        for(char c : mp[a[ind] - '0']){
            temp.push_back(c);
            f(ind+1,a,ans,temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string& a) {
        mp.clear();
        mp[2] = {'a','b','c'};
        mp[3] = {'d','e','f'};
        mp[4] = {'g','h','i'};
        mp[5] = {'j','k','l'};
        mp[6] = {'m','n','o'};
        mp[7] = {'p','q','r','s'};
        mp[8] = {'t','u','v'};
        mp[9] = {'w','x','y','z'};

        vector<string> ans;
        string temp;
        f(0,a,ans,temp);
        return ans;
    }
};