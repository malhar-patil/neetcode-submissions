class Solution {
public:
    bool cycle = false;
    void dfs(int node, vector<int>& visited, stack<int>& st, unordered_map<int, vector<int>>& adj){
        visited[node] = 1;

        for(int i=0;i<adj[node].size();i++){
            int n = adj[node][i];
            if(visited[n] == 1){
                cycle = true;
                return;
            }
            if(visited[n] == 0){
                dfs(n, visited, st, adj);
            }
        }

        visited[node] = 2;
        st.push(node);
        return;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, vector<int>> adj;
        for(int i=0;i<prerequisites.size();i++){
            // if(prerequisites[i][0] == prerequisites[i][1]){return false;}
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> visited(numCourses, 0);
        stack<int> st;

        for(int i=0;i<numCourses;i++){
            if(visited[i] == 0){
                dfs(i, visited, st, adj);
            }
        }

        if(cycle){return {};}

        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res;

    }
};
