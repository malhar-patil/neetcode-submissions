class Heap{
    public:
    vector<pair<double,vector<int>>> heap;
    int size;
    int k;

    Heap(int k){
        heap.assign(k+1,{0.0,{}});
        size=0;
        this->k=k;
    }
    vector<int> deletion(){
        if(size==0){
            return {};
        }
        vector<int>res=heap[1].second;
        heap[1]=heap[size];
        size--;
        swiftDown();
        return res;
    }
    void replaceRoot(pair<double,vector<int>>& p){
        heap[1]=p;
        swiftDown();
    }
    void insert(double& val,vector<int>&point){
        pair<double,vector<int>> p = {val,point};
        if(size>=k && val>=heap[1].first){
            return;
        }
        if(size>=k && val<heap[1].first){
            replaceRoot(p);
        }
        else{
            size++;
            int index=size;
            heap[index]=p;

            while(index>1){
                int parent=index/2;
                if(heap[index].first>heap[parent].first){
                    swap(heap[index],heap[parent]);
                    index=parent;
                }
                else{
                    return;
                }
            }
        }
    }
    private:
    void swiftDown(){
        int index=1;
        while(index<=size){
            int i=index;
            int left=2*i;
            int right=2*i+1;

            if(left<=size && heap[left].first>heap[i].first){
                i=left;
            }
            if(right<=size &&  heap[right].first>heap[i].first){
                i=right;
            }

            if(index!=i){
                swap(heap[index],heap[i]);
                index=i;
            }else{
                return;
            }
        }
    }

};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        Heap h(k);
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
