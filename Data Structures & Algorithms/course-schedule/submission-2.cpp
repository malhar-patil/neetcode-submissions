class Solution {
public:
    bool dfs(int node, vector<int> &visited, vector<int>& dfsCall, unordered_map<int, vector<int>>& adj){

        visited[node] = 1;
        dfsCall[node] = 1;

        for(int i=0;i<adj[node].size();i++){
            int n = adj[node][i];

            if(visited[n] == 1 && dfsCall[n] == 1){
                return true;
            }

            if(visited[n] == 0 && dfs(n, visited, dfsCall, adj)){
                return true;
            }
        }
        dfsCall[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        for(int i=0;i<prerequisites.size();i++){
            if(prerequisites[i][0] == prerequisites[i][1]){return false;}
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> visited(numCourses, 0);
        vector<int> dfsCall(numCourses, 0);
        for(int i=0;i<numCourses;i++){
            if(visited[i] == 0 && dfs(i, visited, dfsCall, adj)){
                return false;
            }
        }
        return true;
    }
};
