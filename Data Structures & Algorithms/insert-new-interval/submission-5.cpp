class Solution {
public:
    void addIntervals(vector<vector<int>>& ans,  int& i, vector<vector<int>>& intervals){

        while(i<intervals.size()){
            ans.push_back(intervals[i]);
            i++;
        }

    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i=0;
        for(i=0;i<intervals.size();i++){
            if(newInterval[1] < intervals[i][0]){
                ans.push_back(newInterval);
                addIntervals(ans, i, intervals);
                return ans;
            }
            else if(newInterval[0] > intervals[i][1]){
                ans.push_back(intervals[i]);
            }
            else{
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }


        ans.push_back(newInterval);
        return ans;
    }
};
