class Solution {
public:
    vector<int> Z_func(string pattern,string text){
        string pattern_Text = pattern + '#' + text;

        int t_len = pattern_Text.size();
        int l = 0, r = 0;
        vector<int> Z(t_len);
        for(int k = 1; k < t_len; k++){
            if(k > r){
                int match = 0;
                while(match + k < t_len && pattern_Text[match] == pattern_Text[match+k])
                ++match;

                Z[k] = match;
                if(match){
                    l = k; 
                    r = k + match - 1;
                }
            }else{
                int p = k - l;
                if(Z[p] < r - k + 1){
                    Z[k] = Z[p];
                }else{
                    int i = r + 1;
                    while(i < t_len && pattern_Text[i] == pattern_Text[i-k]) ++i;

                    Z[k] = i - k;
                    l = k;
                    r = i - 1;
                }
            }
        }

        return Z;
    }
    int strStr(string haystack, string needle) {
        vector<int> Z = Z_func(needle,haystack);

        for(int i = 0; i < Z.size(); i++) {
            if(Z[i] == needle.size()) return i - needle.size()-1;
        }

        for(int i = 0; i < Z.size(); i++) cout << Z[i] <<" " ; 

        return -1;
    }
};