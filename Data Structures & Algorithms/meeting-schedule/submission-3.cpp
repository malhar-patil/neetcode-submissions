/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<vector<int>> nums;
        for(int i=0;i<intervals.size();i++){
            nums.push_back({intervals[i].start, intervals[i].end});
        }
        sort(nums.begin(), nums.end());
        int start = nums[0][0];
        int end = nums[0][1];

        for(int i=1;i<nums.size();i++){
            if(end <= nums[i][0]){
                start = nums[i][0];
                end = nums[i][1];
            }
            else{
                return false;
            }
        }
        return true;
    }
};
