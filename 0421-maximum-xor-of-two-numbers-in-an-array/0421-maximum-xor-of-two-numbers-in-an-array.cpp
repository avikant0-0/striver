class Solution {
public:
    class Trie{
        private:
            vector<Trie*> arr;
        public:
            Trie(){
                arr.assign(2,nullptr);
            }
            void insert(int num){
                Trie* node = this;
                for(int i = 31; i >= 0; i--){
                    int bit = (1&(num>>i));
                    if(node->arr[bit]==nullptr){
                        node->arr[bit] = new Trie();
                    }
                    node = node->arr[bit];
                }
            }
            int maxXOR(int x){
                int ans = 0;
                Trie* node = this;
                for(int i = 31; i >= 0; i--){
                    int xbit = (1&(x>>i));

                    if(node->arr[!xbit] != nullptr){
                        node = node->arr[!xbit];
                        ans = ((1<<i)|ans);

                    }else node = node->arr[xbit];
                }
                return ans;
            }
    };
    int findMaximumXOR(vector<int>& nums) {
        int ans = INT_MIN;
        Trie* T = new Trie();
        for(int i : nums) T->insert(i);
        for(int i : nums) ans = max(ans,T->maxXOR(i));
        return ans;
    }
};