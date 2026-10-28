class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        vector<vector<int>> res;

        for(int i=1;i<intervals.size();i++){
            // if(end < intervals[i][0]){
            //     res.push_back({start, end});
            //     for(int j=i;j<intervals.size();j++){
            //         res.push_back(intervals[j]);
            //     }
            //     return res;
            // }
            // else{
            //     start = min(start, intervals[i][0]);
            //     end = max(end, intervals[i][1]);
            // }

            if(start < intervals[i][0] && end < intervals[i][0]){
                res.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
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
