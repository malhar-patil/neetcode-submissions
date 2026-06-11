class Solution {
public:
    int climbStairs(int n) {
        vector<int> arr;
        arr.push_back(0);
        arr.push_back(1);

        for(int i=2; i<=n+1;i++){
            arr.push_back(arr[i-1] + arr[i-2]);
        }

        return arr[arr.size()-1];
    }
};
