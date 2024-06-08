using ll = long long;
class Solution {
public:
    string clearDigits(string s) {
        for(ll j = s.length() - 1; j >= 0; j--  ) {
        if( !(s[j] <= 'z' && s[j] >= 'a') ) {
           
            for(ll i = j - 1; i >= 0; i-- ) {
                if((s[i] <= 'z' && s[i] >= 'a')) {
                    s.erase(s.begin() + i ) ;
                    break;
                }
            }
            s.erase(s.begin()+j - 1 );
            --j;
        }
    }
    // cout<<s<<endl;
        return s; 
    }
};