class Solution {
public:
    int smallestOne(vector<vector<int>>& intervals, int& query){
        int res = INT_MAX;
        for(int i=0;i<intervals.size();i++){
            if(query >= intervals[i][0] && query <= intervals[i][1]){
                res = min(res, intervals[i][1]-intervals[i][0]+1);
            }
        }
        return res;
    }
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> ans;

        for(int i=0;i<queries.size();i++){
            int res = smallestOne(intervals, queries[i]);
            if(res == INT_MAX){
                ans.push_back(-1);
            }
            else{
                ans.push_back(res);
            }
        }

        return ans;
    }
};
