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
        vector<vector<int>> arr;
        for(int i=0;i<intervals.size();i++){
            arr.push_back({intervals[i].start, intervals[i].end});
        }
        sort(arr.begin(), arr.end());

        for(int i=1;i<arr.size();i++){
            if(arr[i][0] < arr[i-1][1]){
                return false;
            }
        }
        return true;
    }
};
