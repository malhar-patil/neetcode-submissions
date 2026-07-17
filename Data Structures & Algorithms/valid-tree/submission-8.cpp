class Solution {
public:
    bool dfs(int node, unordered_map<int, vector<int>>& adj, vector<int>& visited, int p){
        visited[node] = 1;
        bool res = false;
        
        for(int i=0;i<adj[node].size();i++){
            int n = adj[node][i];
            if(n == p){continue;}
            
            if(visited[n] == 1){
                return true;
            }
            
            if(visited[n] == 0 && dfs(n, adj, visited, node)){
                return true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(int i=0;i<edges.size();i++){
            if(edges[i][0] == edges[i][1]){return false;}
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
            
        vector<int> visited(n, 0);
        
        if(dfs(0, adj, visited, 0)){
            return false;
        }
        for(int i=0;i<n;i++){
            if(visited[i] == 0){
                return false;
            }
        }
        return true;
    }
};
