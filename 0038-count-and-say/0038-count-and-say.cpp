class Solution {
public:
string countAndSay(int n) {
        if(n == 1) return "1";
        
        string behind = countAndSay(n-1); 
        string after = "";

        // cout << behind << endl;
        for(int i = 0; i < behind.size(); i++){
            int cnt = 1; 
            // after += behind[i]; 
            string temp = "";
            temp += behind[i];

            // 1
            for(int j = i + 1 ; j < behind.size(); j++){
                if(behind[j] == behind[j-1]) ++cnt,++i;
                else break;
            }
            temp.insert(0,to_string(cnt));
            after.push_back(temp[0]);
            after.push_back(temp[1]); 
        }

        return after ;
    }
};