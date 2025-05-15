class Solution {
public:
    vector<int> rearrangeArray(vector<int>& a) {
        int pos = 0, neg = 0;
        vector<int> res;
        while(pos < a.size() && neg < a.size()){
            while(a[pos] < 0) ++pos;
            while(a[neg] > 0) ++neg;

            res.push_back(a[pos]);
            res.push_back(a[neg]);

            ++pos,++neg;
        }

        return res;
    }
};