class Solution {
public:
    bool topologySort(unordered_map<int,list<int>>& graph, unordered_map<int,int>& visited, int num){
        visited[num]=1;
        for(auto it = graph[num].begin();it!=graph[num].end();it++){
            if(visited[*it]==1){
                return false;
            }
            if(visited[*it]!=2 && !topologySort(graph,visited,*it)){
                return false;
            }
        }
        visited[num] = 2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> graph;
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        unordered_map<int,int> visited;
        for(int i=0;i<numCourses;i++){
            if(visited[i]==0){
                if(!topologySort(graph,visited,i)){
                    return false;
                }
            }
        }
        return true;
    }
};
