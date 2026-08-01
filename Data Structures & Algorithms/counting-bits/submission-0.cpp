class Solution {
public:
    int count(int n){
        int ans = 0;
        while(n>0){
            if(n&1 == 1){
                ans++;
            }
            n=n>>1;
        }
        return ans;
    }
    vector<int> countBits(int n) {
        vector<int> res;

        for(int i=0;i<=n;i++){
            res.push_back(count(i));
        }
        return res;

    }
};
