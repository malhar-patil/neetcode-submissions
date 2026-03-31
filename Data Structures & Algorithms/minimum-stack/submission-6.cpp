class MinStack {
public:
    vector<int> st;
    vector<int> minNum;
    int index;
    MinStack() {
        this->index=0;
    }
    
    void push(int val) {
        st.push_back(val);
        if(minNum.size()==0){
            minNum.push_back(val);
            return;
        }
        minNum.push_back(min(val,minNum[minNum.size()-1]));
    }
    
    void pop() {
        if(!st.empty()){
            st.pop_back();
            minNum.pop_back();
        }
    }
    
    int top() {
        return st[st.size()-1];
    }
    
    int getMin() {
        return minNum[minNum.size()-1];
    }
};
