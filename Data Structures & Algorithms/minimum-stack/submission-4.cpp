class MinStack {
public:
    vector<int> st;
    vector<int> minArr;
    int index;
    int minNum=INT_MAX;
    MinStack() {
        st.assign(1,0);
        minArr.assign(1,0);
        index=0;
    }
    
    void push(int val) {
        st[index] = val;
        minNum = min(minNum,val);
        minArr[index] = minNum;
        index++;
    }
    
    void pop() {
        index--;
        if(index-1>=0){
            minNum=minArr[index-1];
        }
        else{
            minNum=INT_MAX;
        }
    }
    
    int top() {
        return st[index-1];
    }
    
    int getMin() {
        return minArr[index-1];
    }
};
