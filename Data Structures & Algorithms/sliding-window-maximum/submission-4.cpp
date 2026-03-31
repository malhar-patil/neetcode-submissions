class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> ans;

        for(int i=0;i<k && i<nums.size();i++){
            pq.push({nums[i],i});
        }
        ans.push_back(pq.top().first);

        int l=1;
        for(int r=k;r<nums.size();r++){
            pq.push({nums[r],r});
            while(pq.top().second<(r-k+1)){
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};
