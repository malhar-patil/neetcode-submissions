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
        if(intervals.size() == 0){
            return true;
        }
        sort(intervals.begin(), intervals.end(), 
        [](const Interval& a, Interval&b){
            return a.start < b.start;
        });
        int end = intervals[0].end;

        for(int i=1;i<intervals.size();i++){
            if(end <= intervals[i].start){
                end = intervals[i].end;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
