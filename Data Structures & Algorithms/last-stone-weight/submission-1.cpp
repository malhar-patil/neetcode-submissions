class Heap{
    public:
    vector<int>heap;
    int size;

    Heap(int val){
        heap.assign(val+1,0);
        size=0;
    }

    void insert(int val){
        size++;
        int index=size;
        heap[index]=val;

        while(index>1){
            int parent = index/2;
            if(heap[index]>heap[parent]){
                swap(heap[index],heap[parent]);
                index=parent;
            }
            else{
                return;
            }
        }
    }

    int deletion(){
        if(size==0){
            return -1;
        }
        int res = heap[1];
        heap[1]=heap[size];
        size--;
        int index=1;

        while(index<=size){
            int i=index;
            int left = 2*i;
            int right = 2*i+1;

            if(left<=size && heap[left]>heap[i]){
                i=left;
            }
            if(right<=size && heap[right]>heap[i]){
                i=right;
            }

            if(index!=i){
                swap(heap[index],heap[i]);
                index=i;
            }
            else{
                break;
            }
        }
        return res;
    }

    void print(){
        for(int i=0;i<=size;i++){
            cout<<heap[i]<<" ";
        }
        cout<<endl;
    }
};

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        Heap h(stones.size());
        for(int i=0;i<stones.size();i++){
            h.insert(stones[i]);
        }

        while(h.size!=0){
            int x = h.deletion();
            int y = h.deletion();

            if(y==-1){return x;}
            if(x==y){continue;}
            h.insert(abs(x-y));
            cout<<"HI"<<endl;
        }
        return 0;
    }
};
