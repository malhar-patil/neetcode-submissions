class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> heap;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i=0;i<nums.size();i++){
            if(heap.empty()){
                heap.push(nums[i]);
                continue;
            }
            if(nums[i] > heap.top() && heap.size() == this->k){
                heap.pop();
                heap.push(nums[i]);
            }
            else if(heap.size() < this->k){
                heap.push(nums[i]);
            }
        }
    }
    
    int add(int val) {

        if(heap.empty()){
            heap.push(val);
            return heap.top();
        }

        if(val > heap.top() && heap.size() == k){
            heap.pop();
            heap.push(val);
        }
        else if(heap.size() < k){
            heap.push(val);
        }
        return heap.top();
    }
};
