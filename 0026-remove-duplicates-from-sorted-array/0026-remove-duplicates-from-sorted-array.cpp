class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int i = 0, j = 0;
        while( i < a.size() && j < a.size() ){
            if(a[i] == a[j]){
                ++j;
            }else{
                ++i;
                a[i] = a[j];
            }
        }
        for(int j = a.size() -1 ; j > i; j--){
            a[j] = 0;
        }
        return i + 1; 
    }
};