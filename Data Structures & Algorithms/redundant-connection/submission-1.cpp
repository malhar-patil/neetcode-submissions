class Solution {
public:
    int findParent(vector<int> &parent, int node){
        if(parent[node] == node){
            return node;
        }
        parent[node] = findParent(parent, parent[node]);
        return parent[node];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<int> parent(n,0);
        vector<int> rank(n,0);

        for(int i=0;i<n;i++){
            parent[i] = i;
            rank[i] = 0; 
        }
        vector<int> res;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];

            int pu = findParent(parent, u);
            int pv = findParent(parent, v);

            if (pv == pu){
                res = edges[i];
            }

            if(rank[pu] == rank[pv]){
                parent[pv] = pu;
                rank[pu]++;
            }
            else if(rank[pu] < rank[pv]){
                parent[pu] = pv;
            }
            else{
                parent[pv] = pu;
            }
        }
        return res;
    }
};
