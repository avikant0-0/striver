class Solution {
public:
    bool lemonadeChange(vector<int>& a) {
        int five = 0, ten = 0,twenty = 0;
        for(int i = 0; i < a.size(); i++){
            int toreturn = a[i] - 5;
            if(a[i] == 5) ++five;
            if(a[i] == 10) ++ten;
            if(a[i] == 20) ++twenty;
            
            while(toreturn > 0){
                if(twenty > 0 && toreturn >= 20){
                    toreturn -= 20;
                    --twenty;
                }
                else if(ten > 0 && toreturn >= 10){
                    toreturn -= 10;
                    --ten;
                }
                else if(five > 0 && toreturn >= 5){
                    toreturn -= 5;
                    --five;
                }
                else return false;
            }
        }
        return true;
    }
};