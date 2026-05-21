class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //pair<int, vector<int>> ; 
        priority_queue<pair<int, vector<int>>> heap;
        for(int i=0;i<points.size();i++){
            int distance = (pow(points[i][0],2) + pow(points[i][1], 2));
            cout<<distance<<endl;
            if(heap.empty()){
                heap.push({distance, points[i]});
                continue;
            } 
            if(distance <= heap.top().first && heap.size() >= k){
                heap.pop();
                heap.push({distance, points[i]});
            }
            else if(heap.size() < k){
                heap.push({distance, points[i]});
            }
        }
        vector<vector<int>> ans;
        cout<<heap.size()<<endl;
        while(!heap.empty()){
            ans.push_back(heap.top().second);
            heap.pop();
        }
        return ans;
    }
};
