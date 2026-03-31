class MinStack {
public:
    vector<int> stack;
    vector<int> minArr;
    int stackMin;
    int index;

    MinStack() {
        stack.assign(1,0);
        minArr.assign(1,0);
        stackMin = INT_MAX;
        index=0;
    }
    
    void push(int val) {
        stack[index] = val;
        minArr[index] = min(stackMin, val);
        stackMin = minArr[index];
        index++;
    }
    
    void pop() {
        index--;
        if(index == 0){
            stackMin = INT_MAX;
        }
        else{
            stackMin = minArr[index-1];
        }
    }
    
    int top() {
        return stack[index-1];
    }
    
    int getMin() {
        return minArr[index-1];
    }
};
