class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int s = intervals[0][0];
        int e = intervals[0][1];
        vector<vector<int>> ans;
        
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] <= e){
                s = min(s, intervals[i][0]);
                e = max(e, intervals[i][1]);
            }
            else if(e < intervals[i][0]){
                ans.push_back({s,e});
                s = intervals[i][0];
                e = intervals[i][1];
            }
            else if(intervals[i][0] > e){
                ans.push_back(intervals[i]);
            }
        }
        ans.push_back({s,e});
        return ans;
    }
};
