class Solution {
public:
    vector<int> prefix_function(string s){
        int n = s.length();
        vector<int> prefix(n,0);

        for(int i = 1 ;i < n; i++){
            int j = prefix[i-1];

            while( j > 0 && s[i] != s[j]){
                j = prefix[j-1];
            }
            if(s[i] == s[j]) {
                ++j;
            }
            prefix[i] = j; 
        }

        return prefix; 
    }
    int strStr(string haystack, string needle) {
        vector<int> prefix = prefix_function(needle);

        int i = 0 , j = 0, pos = -1;

        while( i < haystack.size()){
            if(haystack[i] == needle[j]) ++i,++j;
            else if(j != 0) j = prefix[j-1];
            else ++i; 

            if( j == needle.size()) {
            pos = i - needle.size();
            break;
            }
        
        }

       
        return pos; 
    }
};