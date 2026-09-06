class MinStack {
public:
    vector<int> st;
    vector<int> minNum;
    int index;
    MinStack() {
        index=0;
        st.assign(30000,0);
        minNum.assign(30000,0);
    }
    
    void push(int val) {
        st[index] = val;
        if(index>0){
            minNum[index] = min(minNum[index-1], val);
        }
        else{
            minNum[index] = val;
        }
        index++;
    }
    
    void pop() {
        index--;

    }
    
    int top() {
        return st[index-1];
    }
    
    int getMin() {
        return minNum[index-1];
    }
};
