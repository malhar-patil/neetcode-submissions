class Solution {
public:
    bool isPossible(vector<int>&piles, long long maxRate, int h){
        int time = 0;
        for(int i=0;i<piles.size();i++){
            if(piles[i] <= maxRate){
                time++;
                continue;
            }

            if(piles[i]%maxRate == 0){
                time += (piles[i]/maxRate);
            }
            else{
                time += (piles[i]/maxRate + 1);
            }
        }

        if(time <= h){
            return true;
        }
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long minTime = 0;

        long long total = 0;
        for(int i=0;i<piles.size();i++){
            total += piles[i];
        }

        long long s = 1;
        long long e = total;

        while(s<=e){
            long long mid = s+(e-s)/2;

            if(isPossible(piles, mid, h)){
                minTime = mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }

        return minTime;
    }
};
