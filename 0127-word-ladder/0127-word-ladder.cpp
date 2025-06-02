class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        set<string> st(wordList.begin(),wordList.end());
        int n = wordList.size(),m = beginWord.size();

        queue<pair<string,int>> q;
        q.push({beginWord,1});

        while(!q.empty())
        {
            pair<string,int> top = q.front();
            q.pop();
            if(top.first == endWord) return top.second;

            for(int i = 0; i < m; i++)
            {   
                string s = top.first;
                for(char c = 'a'; c <= 'z'; c++)
                {
                    s[i] = c;
                    if(st.find(s) == st.end()) continue;
                    q.push({s,top.second+1});
                    st.erase(s);
                }
            }
        }

        return 0;
    }
};