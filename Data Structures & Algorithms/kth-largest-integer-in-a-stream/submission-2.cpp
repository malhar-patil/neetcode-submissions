class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int size;
    KthLargest(int k, vector<int>& nums) {
        this->size = k;
        for(int i=0;i<nums.size();i++){
            if(minHeap.size() < k){
                minHeap.push(nums[i]);
            }
            else if(minHeap.size() == k && nums[i] >= minHeap.top()){
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        cout<<minHeap.size()<<endl;
        if(minHeap.size() < size){
            minHeap.push(val);
        }
        else if(minHeap.size() == size && val >= minHeap.top()){
            minHeap.pop();
            minHeap.push(val);
        }
        return minHeap.top();
    }
};
