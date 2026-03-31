class Solution {
public:
    bool res=false;
    void solve(unordered_map<int,vector<int>>& graph,unordered_map<int,int>& visited, int num,int p){
        visited[num] = true;
        for(int i=0;i<graph[num].size();i++){
            if(graph[num][i] == p){continue;}
            if(visited[graph[num][i]]){
                res = false;
                return;
            }
            solve(graph,visited, graph[num][i],num);
        }
        if(num != p){
            res=true;
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()==0){
            return true;
        }
        unordered_map<int,vector<int>> graph;
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        unordered_map<int,int> visited;
        solve(graph,visited,0,0);
        if(res && visited.size()==n){return true;}
        return false;
    }
};
