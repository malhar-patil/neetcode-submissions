class Solution {
public:
    void dfs(unordered_map<int,vector<int>> graph,unordered_map<int,bool>& visited, int num){
        visited[num]=true;
        for(int i=0;i<graph[num].size();i++){
            if(visited[graph[num][i]]){continue;}
            dfs(graph,visited,graph[num][i]);
        }
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> graph;
        unordered_map<int,bool> visited;
        int res = 0;
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                res++;
                dfs(graph,visited,i);
            }
        }
        return res;
    }
};
