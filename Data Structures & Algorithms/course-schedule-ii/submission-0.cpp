class Solution {
public:
    bool topologySort(unordered_map<int,list<int>>& graph, unordered_map<int,int>& visited, queue<int>&s, int num){
        visited[num] = 1;
        for(auto it=graph[num].begin();it!=graph[num].end();it++){
            if(visited[*it]==1){
                return false;
            }
            if(visited[*it]!=2 &&!topologySort(graph,visited,s,*it)){
                return false;
            }
        }

        s.push(num);
        visited[num]=2;
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> graph;
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        unordered_map<int,int> visited;
        queue<int> s;
        for(int i=0;i<numCourses;i++){
            if(visited[i]!=2 && !topologySort(graph,visited,s,i)){
                return {};
            }
        }
        vector<int> res;
        while(!s.empty()){
            res.push_back(s.front());
            s.pop();
        }
        return res;
    }
};
