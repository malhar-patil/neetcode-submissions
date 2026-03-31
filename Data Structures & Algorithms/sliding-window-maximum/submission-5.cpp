class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        for(int i=0;i<k && i<nums.size();i++){
            if(dq.empty()){
                dq.push_front(i);
                continue;
            }

            while(!dq.empty() && nums[i]>nums[dq.back()]){
                dq.pop_back();
            }

            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);

        for(int r=k;r<nums.size();r++){
            while(!dq.empty() && (nums[r]>nums[dq.back()])){
                dq.pop_back();
            }
            while(!dq.empty() && dq.front()<r-k+1){
                dq.pop_front();
            }
            dq.push_back(r);
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
