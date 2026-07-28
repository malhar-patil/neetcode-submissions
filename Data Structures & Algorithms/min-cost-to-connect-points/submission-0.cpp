class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<int> key(n, INT_MAX);
        vector<int> mst(n, false);

        key[0] = 0;

        for(int i=0;i<n;i++){
            int mini = INT_MAX;
            int pt = -1;

            for(int i=0;i<key.size();i++){
                if(mst[i] == false && key[i] < mini){
                    mini = key[i];
                    pt = i;
                }
            }

            mst[pt] = true;
            for(int i=0;i<n;i++){
                if(i == pt){continue;}
                int x1 = points[pt][0];
                int y1 = points[pt][1];
                int x2 = points[i][0];
                int y2 = points[i][1];
                int dist = abs(x1-x2) + abs(y1-y2);
                if(mst[i] == false && dist < key[i]){
                    key[i] = dist;
                }
            }
        } 
        int res = 0;
        for(int i=0;i<key.size();i++){
            res += key[i];
        }
        return res;
    }


};
