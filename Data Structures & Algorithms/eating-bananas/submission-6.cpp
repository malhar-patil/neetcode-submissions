class Solution {
public:
    bool isPossible(vector<int>& piles, int h,long long mid){
        if(mid==0){return false;}
        long long totalEatingTime=0;
        for(int i=0;i<piles.size();i++){
            totalEatingTime += (piles[i] + mid - 1) / mid;
        }

        if(totalEatingTime<=h){
            return true;
        }
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long total = 0;
        for(int i=0;i<piles.size();i++){
            total+=piles[i];
        }

        long long s=0;
        long long e=total;
        long long mid=s+(e-s)/2;
        long long ans=0;
        while(s<=e){
            if(isPossible(piles,h,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
};
