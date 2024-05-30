class Solution {
public:
    void sortColors(vector<int>& a) {
        int one = 0 ,two = 0 , zero = 0 ; 
        for(int i =0 ; i < a.size() ; i++ ) {
            if(a[i] == 0 ) ++zero ;
            if(a[i] == 1 ) ++one ;
            else ++two ;
        }
        for(int i =0 ; i < a.size() ; i++ ) {
            if(zero > 0 ) {
                a[i] = 0 ; 
                zero--;
            }
            else if( one > 0 ) {
                a[i] =1 ; 
                one-- ; 
            }
            else {
                a[i] = 2;
                two--; 
            }
        }
    } 
};