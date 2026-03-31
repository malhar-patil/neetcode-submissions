class Solution {
public:
    bool isPossible(vector<int>& piles, long long h, long long mid){
        if(mid==0){
            return false;
        }
        int cnt = 0;
        for(int i=0;i<piles.size();i++){
            if(piles[i]<=mid){
                cnt++;
            }
            else{
                cnt += ((piles[i]/mid));
                if(piles[i]%mid != 0){
                    cnt++;
                }
            }

        }
        if(cnt>h){
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
        long long res = -1;
        while(s<=e){
            long long mid = s+(e-s)/2;
            cout<<mid<<endl;
            if(isPossible(piles, h, mid)){
                res=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return res;
    }
};
