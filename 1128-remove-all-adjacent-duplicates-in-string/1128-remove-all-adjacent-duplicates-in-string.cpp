class Solution {
public:
    void eraseit(string &s) {
    int n = s.length();
    for(int i =0 ; i < n - 1 ;i++) {
        if(s[i] == s[i+1]) {
            s.erase(s.begin()+i+1);
            s.erase(s.begin()+i);
            break;
        }
    }
}
    string removeDuplicates(string s) {
        string temp = s ;
        while(true){
            eraseit(s);
            if(s == temp ) break;
            temp = s; 
        }
        return s; 
    }
};