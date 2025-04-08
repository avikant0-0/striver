class Solution {
public:

    vector<int> Z_func(string pattern,string text){
        string patternText = pattern + "$" + text;
        int len = patternText.size();

        int l = 0, r = 0;
        vector<int> Z(len);

        for(int k = 1; k < len; k++){
            if(k > r){
                int match = 0;
                while(match + k < len && patternText[match+k] == patternText[match])
                ++match;

                Z[k] = match;

                if(match){
                    l = k;
                    r = match + k - 1;
                }

            }else{
                int p = k - l;
                if(Z[p] < r - k + 1){
                    Z[k] = Z[p];
                }else{
                    int i = r + 1;
                    while(i < len && patternText[i] == patternText[i-k]) 
                    ++i;

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


        for(int i = 0; i < Z.size(); i++){
            if(Z[i] == needle.size()) return i - needle.size() - 1;
        }
 
        return -1;
    }
};