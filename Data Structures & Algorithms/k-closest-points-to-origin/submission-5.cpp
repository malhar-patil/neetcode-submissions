class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<
            pair<int,vector<int>>,
            vector<pair<int,vector<int>>>,
            greater<pair<int,vector<int>>>
        > pq;

        for(int i=0;i<points.size();i++){
            int distance = pow(points[i][0],2) + pow(points[i][1],2);
            pq.push({distance, points[i]});
        }

        vector<vector<int>> res;
        while(k>0 && pq.size()>0){
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return res;
    }
};
