class MedianFinder {
public:

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int totalElements;

    MedianFinder() {
        totalElements = 0;
    }
    
    void addNum(int num) {
        if(minHeap.empty() && maxHeap.empty()){
            minHeap.push(num);
            totalElements++;
            return;
        }
        
        if(num > minHeap.top()){
            minHeap.push(num);
        }
        else{
            maxHeap.push(num);
        }
        totalElements++;

        if(minHeap.size() > maxHeap.size() && minHeap.size() - maxHeap.size() > 1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        if(minHeap.size() < maxHeap.size() && maxHeap.size() - minHeap.size() > 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        cout<<minHeap.size()<<" "<<maxHeap.size()<<endl;
        if(totalElements % 2 == 0){
            return (double)(minHeap.top() + maxHeap.top()) / 2;
        }
        else if(maxHeap.size() > minHeap.size()){
            return (double)maxHeap.top();
        }
        else{
            return (double)minHeap.top();
        }
        
    }
};
