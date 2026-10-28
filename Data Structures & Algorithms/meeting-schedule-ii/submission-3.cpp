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
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size() == 0){
            return 0;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        int res = 0;

        sort(intervals.begin(), intervals.end(), 
        [](const Interval&a, Interval&b){
            return a.start < b.start;
        });
        int end = intervals[0].end;
        pq.push(intervals[0].end);

        for(int i=1;i<intervals.size();i++){
            res = max(res, (int)pq.size());
            while(!pq.empty() && pq.top() <= intervals[i].start){
                pq.pop();
            }
            if(intervals[i].start < end){
                pq.push(intervals[i].end);
                end = max(end, intervals[i].end);
            }
        }
        res = max(res, (int)pq.size());
        return res;
    }
};


