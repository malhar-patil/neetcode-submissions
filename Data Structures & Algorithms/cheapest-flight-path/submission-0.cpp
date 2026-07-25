class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int,int>>> adj;

        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});
        vector<int> minStops(n, INT_MAX);
        minStops[src] = 0;


        while(!pq.empty()){


            int node = pq.top()[1];
            int dist = pq.top()[0];
            int curr_k = pq.top()[2];
            pq.pop();
            if(node == dst) {return dist;}


            if(curr_k > k || curr_k > minStops[node]){continue;}

            minStops[node] = curr_k;
            for(int i=0;i<adj[node].size();i++){
                int node2 = adj[node][i].first;
                int dist2 = adj[node][i].second;
                
                pq.push({dist+dist2, node2, curr_k+1});
            }
        }
        return -1;
    }
};