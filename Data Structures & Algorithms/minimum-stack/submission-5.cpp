class MinStack {
public:
    vector<int> st;
    vector<int> minNum;
    int index;
    MinStack() {
        st.assign(1,0);
        minNum.assign(1,0);
        index=0;
    }
    
    void push(int val) {
        st[index]=val;
        if(index==0){
            minNum[index]=val;
        }
        else{
            minNum[index] = min(val,minNum[index-1]);
        }
        index++;
    }
    
    void pop() {
        index--;
    }
    
    int top() {
        if(index>0){
            return st[index-1];
        }
        return st[index];
    }
    
    int getMin() {
        if(index>0){
            return minNum[index-1];
        }
        return minNum[index];
    }
};
