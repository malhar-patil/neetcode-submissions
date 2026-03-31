class MedianFinder {
public:
    int left;
    int right;
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;

    MedianFinder() {
        left=0;
        right=0;
    }
    
    void addNum(int num) {
        if(minHeap.size()==0 && maxHeap.size()==0){
            maxHeap.push(num);
            left++;
            return;
        }

        if(num>maxHeap.top()){
            minHeap.push(num);
            right++; 
        }
        else{
            maxHeap.push(num);
            left++; 
        }

        if(abs(left-right)>1 && left>right){
            int topElement = maxHeap.top();
            maxHeap.pop();
            left--;
            minHeap.push(topElement);
            right++;         
        }
        else if(abs(left-right)>1 && right>left){
            int topElement = minHeap.top();
            minHeap.pop();
            right--;
            maxHeap.push(topElement);
            left++;     
        }
        return;
    }
    
    double findMedian() {
        if(left==right){
            return (maxHeap.top()+minHeap.top())/(double)2;
        }
        else if(left>right){
            return double(maxHeap.top());
        }
        else{
            return double(minHeap.top());
        }
    }
};
