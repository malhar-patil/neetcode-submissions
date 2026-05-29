class Solution {
public:
    bool isPossible(vector<int>& piles, long long h, long long rate){
        long long totalTime = 0;

        for(int i=0;i<piles.size();i++){
            if(piles[i] <= rate){
                totalTime++;
            }
            else{
                totalTime += (piles[i]/rate);
                if(piles[i] % rate != 0){
                    totalTime++;
                }
            }

            if(totalTime > h){
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long totalBananas = 0;
        for(int i=0;i<piles.size();i++){
            totalBananas += piles[i];
        }

        long long s = 1;
        long long e = totalBananas;

        long long rate = 0;

        while(s <= e){
            long long mid = s+(e-s)/2;

            if(isPossible(piles, h, mid)){
                rate = mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return rate;
    }
};
