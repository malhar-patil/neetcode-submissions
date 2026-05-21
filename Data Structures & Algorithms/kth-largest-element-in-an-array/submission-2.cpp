class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap;

        for(int i=0;i<nums.size();i++){
            if(heap.empty()){
                heap.push(nums[i]);
                continue;
            }

            if(nums[i] >= heap.top() && heap.size() == k){
                heap.pop();
                heap.push(nums[i]);
            }
            else if(heap.size() < k){
                heap.push(nums[i]);
            }
        }
        return heap.top();
    }
};
