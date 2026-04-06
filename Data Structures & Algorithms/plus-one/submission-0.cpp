class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.size() == 0){
            return {1};
        }
        stack<int> s;
        int sum =0 ;
        int carry = 0;

        sum = (carry + digits[digits.size()-1]+1)%10;
        carry = (carry + digits[digits.size()-1]+1)/10;
        s.push(sum);

        for(int i=digits.size()-2;i>=0;i--){
            sum = (carry + digits[i])%10;
            carry = (carry + digits[i])/10;
            s.push(sum);
        }
        if(carry!=0){
            s.push(carry);
        }
        digits.clear();
        while(!s.empty()){
            digits.push_back(s.top());
            s.pop();
        }
        return digits;
    }
};
