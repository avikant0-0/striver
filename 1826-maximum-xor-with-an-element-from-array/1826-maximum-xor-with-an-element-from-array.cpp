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
                    if(node->arr[bit] == nullptr){
                        node->arr[bit] = new Trie();
                    }
                    node = node->arr[bit];
                }
            }

            int maxXOR(int x){
                int ans = 0;
                Trie* node = this;
                for(int i = 31; i >= 0; i--){
                    int bit = ((x>>i)&1);
                    int want  = !bit;

                    if(node->arr[want]!=nullptr){
                        ans |= (1<<i);
                        node = node->arr[want];
                    }
                    
                    else node = node->arr[bit];
                }
                return ans;
            }
    };
    vector<int> maximizeXor(vector<int>& a, vector<vector<int>>& q) {
        sort(a.begin(),a.end());
        int m = q.size(), n = a.size();

        vector<tuple<int,int,int>> q1;
        for(int i = 0; i < m; i++) q1.push_back({q[i][0],q[i][1],i});

        sort(q1.begin(),q1.end(),[&](auto& a,auto& b){
            return get<1>(a) < get<1>(b) ;
        });

        int i = 0, j = 0;
        Trie* T = new Trie();
        vector<int> answer(m,-1);

        while(j < m){
            if(i < n && a[i] <= get<1> (q1[j])) T->insert(a[i]),++i;
            else{
                if(i == 0) {
                    ++j;
                    continue;
                } 
                int ans = -1;
                int x = get<0> (q1[j]);
                ans = max(ans,T->maxXOR(x));
                answer[get<2> (q1[j])] = ans;
                ++j;
            }
        }

        return answer;
    }
};