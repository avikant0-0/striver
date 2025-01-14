class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = ( b.length() + a.length() - 1 )/ a.length();
        cout << n << endl;
        string c = "";
        for(int i = 0; i < n  ; i++) c = c + a; 

        cout << c << endl; 

        for(int i =0; i < 2; i++){
            if(c.find(b)!=string::npos){
                return n + i ; 
            }
            c = c + a;
        }
        return -1; 
    }
};