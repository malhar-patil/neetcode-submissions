class Solution {
public:
    void bfs(int node, vector<int>& visited, unordered_map<int, vector<int>>& adj){
        queue<int>q;
        q.push(node);
        visited[node] = 1;

        while(!q.empty()){
            int temp = q.front();
            q.pop();

            for(int i=0;i<adj[temp].size();i++){
                int n = adj[temp][i];
                if(visited[n] == 0){
                    q.push(n);
                    visited[n] = 1;
                }
            }
        }
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int>visited(n,0);
        int res = 0;
        for(int i=0;i<n;i++){
            if(visited[i] == 0){
                res++;
                bfs(i, visited, adj);
            }
        }
        return res;
    }
};
