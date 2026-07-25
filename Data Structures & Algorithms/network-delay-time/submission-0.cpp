class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> adj;

        for(int i=0;i<times.size();i++){
            adj[times[i][0]-1].push_back({times[i][1]-1, times[i][2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> res(n,INT_MAX);
        res[k-1] = 0;

        pq.push({0, k-1});

        while(!pq.empty()){
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            if(dist > res[node]){
                continue;
            }

            for(int i=0;i<adj[node].size();i++){
                int node2 = adj[node][i].first;
                int dist2 = adj[node][i].second;

                if(dist + dist2 < res[node2]){
                    res[node2] = dist+dist2;
                    pq.push({res[node2], node2});
                }
            }
        }

        int ans = 0;
        for(int i=0;i<res.size();i++){
            if(res[i] == INT_MAX){return -1;}
            ans= max(ans, res[i]);
        }

        return ans;
    }
};
