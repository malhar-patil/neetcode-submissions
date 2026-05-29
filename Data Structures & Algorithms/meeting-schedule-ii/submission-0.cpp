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
        vector<int> arr1;
        vector<int> arr2;

        for(int i=0;i<intervals.size();i++){
            arr1.push_back(intervals[i].start);
            arr2.push_back(intervals[i].end);
        }
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());

        int s1 = 0;
        int s2 = 0;
        int maxCnt = 0;
        int count = 0;

        while(s1 < arr1.size() && s2 < arr2.size()){
            if(arr1[s1] < arr2[s2]){
                count++;
                maxCnt = max(maxCnt, count);
                s1++;
            }
            else{
                count--;
                s2++;
            }
        }
        return maxCnt;
    }
};
