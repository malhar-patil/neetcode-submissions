class KthLargest {
public:
    vector<int>heap;
    int size;
    int k;
    //min-heap
    void deletion(){
        heap[1] = heap[size];
        size--;

        int index=1;
        while(index<size){
            int child1 = 2*index;
            int child2 = 2*index+1;
            int i=index;
            if(child1<=size && heap[child1]<heap[i]){
                i=child1;
            }
            if(child2<=size &&  heap[child2]<heap[i]){
                i=child2;
            }

            if(i!=index){
                swap(heap[index],heap[i]);
                index=i;
            }
            else{
                return;
            }
        }
    }
    void insert(int val){
        if(size >= this->k && val<=heap[1]){
            return;
        }
        if(size >= this->k && val>heap[1]){
            deletion();
        }
        size++;
        int index=size;
        heap[index] = val;

        while(index>1){
            int parent = index/2;
            if(heap[index]<heap[parent]){
                swap(heap[index],heap[parent]);
                index=parent;
            }
            else{
                return;
            }
        }
    }
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        heap.assign((this->k)+1,0);
        size = 0;

        for(int i=0;i<nums.size();i++){
            insert(nums[i]);
        }

        for(int i=0;i<=size;i++){
            cout<<heap[i]<<" ";
        }cout<<endl;
    }
    
    int add(int val) {
        insert(val);
        return heap[1];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */