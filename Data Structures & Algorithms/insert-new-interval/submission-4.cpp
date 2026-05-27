class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() == 0){
            return {newInterval};
        }
        vector<vector<int>> ans;
        // if(newInterval[1] < intervals[0][1]){
        //     ans.push_back(newInterval);
        //     for(int i=0;i<intervals.size();i++){
        //         ans.push_back(intervals[i]);
        //     }
        //     return ans;
        // }
        // if(newInterval[0] >intervals[intervals.size()-1][0]){
        //     for(int i=0;i<intervals.size();i++){
        //         ans.push_back(intervals[i]);
        //     }
        //     ans.push_back(newInterval);
        //     return ans;
        // }
        bool newIntervalInserted = false;
        int i = 0;
        for(i=0;i<intervals.size();i++){
            if(newInterval[0] <= intervals[i][1] && newInterval[1] >= intervals[i][0]){
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            }
            else if(newInterval[1] < intervals[i][0]){
                ans.push_back(newInterval);\
                newIntervalInserted=true;
                break;
            }
            else{
                ans.push_back(intervals[i]);
            }
            cout<<newInterval[0]<<" "<<newInterval[1]<<endl;
        }
        if(!newIntervalInserted){
            ans.push_back(newInterval);
        }
        while( i < intervals.size()){
            ans.push_back(intervals[i++]);
        }
        return ans;
    }
};
