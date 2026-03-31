class Heap{
    public:
    vector<pair<double,vector<int>>> heap;
    int size;

    Heap(int val){
        heap.assign(val+1,{0.0,{}});
        size=0;
    }
    vector<int> deletion(){
        if(size==0){
            return {};
        }
        vector<int>res=heap[1].second;
        heap[1]=heap[size];
        size--;

        int index=1;
        while(index<=size){
            int i=index;
            int left=2*i;
            int right=2*i+1;

            if(left<=size && heap[left]<heap[i]){
                i=left;
            }
            if(right<=size && heap[right]<heap[i]){
                i=right;
            }

            if(index!=i){
                swap(heap[index],heap[i]);
                index=i;
            }
            else{
                return res;
            }
        }
        return res;
    }
    void insert(double val,vector<int>point){
        size++;
        int index=size;

        pair<double,vector<int>> p = {val,point};
        heap[index]=p;

        while(index>1){
            int parent=index/2;
            if(heap[index].first<heap[parent].first){
                swap(heap[index],heap[parent]);
                index=parent;
            }
            else{
                return;
            }
        }
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        Heap h(points.size());
        for(int i=0;i<points.size();i++){
            double distance = sqrt(pow(points[i][0],2)+pow(points[i][1],2));
            h.insert(distance,points[i]);


        }
        vector<vector<int>> res;
        while(k>0){
            res.push_back(h.deletion());
            k--;
        }
        return res;
    }
};
