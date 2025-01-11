class Solution {
public:
    bool check(int node,int c,vector<int>& color, auto& adj){
        color[node] = c; 

        for (int adjacent : adj[node]){
            if(color[adjacent] == -1){
                if( check(adjacent,!c,color,adj) == false){
                    return false; 
                }
            }
            else  if( c == color[adjacent] ){
                return  false; 
            }
        }

        return true; 
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int totalNodes = graph.size();
        vector<int> color(totalNodes,-1);

        for(int node = 0; node < totalNodes;node++){
            if(color[node] == -1){
                if( check(node,0,color,graph) == false ) return false;
            }
        }
        return true; 
    }
};