class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        int start = newInterval[0];
        int end = newInterval[1];

        int i=0;
        for(i=0;i<intervals.size();i++){
            if(end < intervals[i][0]){
                res.push_back({start, end});
                for(int j=i;j<intervals.size();j++){
                    res.push_back(intervals[j]);
                }
                return res;
            }
            else if(start > intervals[i][1]){
                res.push_back(intervals[i]);
            }
            else{
                start = min(start, intervals[i][0]);
                end = max(end, intervals[i][1]);
            }
        }

        res.push_back({start, end});
        return res;
    }
};
