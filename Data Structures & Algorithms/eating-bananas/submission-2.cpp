class Solution {
public:
    bool isPossible(int h, int k, vector<int>& piles){
        long long timeRequired=0;
        for(int i=0;i<piles.size();i++){
            if(piles[i]<=k){
                timeRequired++;
                continue;
            }
            else{
                timeRequired += piles[i]/k;
                if(piles[i]%k!=0){
                    timeRequired++;
                }
            }
        }

        if(timeRequired>h){
            return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long s=0;
        long long e=0;
        for(int i=0;i<piles.size();i++){
            e+=piles[i];
        }
        long long mid = s+(e-s)/2;
        int ans=-1;

        while(s<=e && mid!=0){
            if(isPossible(h,mid,piles)){
                ans = mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid = s+(e-s)/2;
        }
        return ans;
    }
};
