#include <vector>
using namespace std;

class Solution {
public:
    vector<int> visited;
    void dfs(int u, vector<vector<int>>& adj, int& v, int& e) {
        visited[u] = 1;
        ++v;
        for (int w : adj[u]) {
            ++e;
            if (!visited[w]) {
                dfs(w, adj, v, e);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        visited.assign(n, 0);
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int v = 0, e = 0;
                dfs(i, adj, v, e);
                e /= 2;
                if (e == v * (v - 1) / 2) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};
