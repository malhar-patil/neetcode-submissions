class Solution {
public:
    void solve(string digits, vector<string>mapping, vector<string>& ans, string temp, int index){
        if(index >= digits.length()){
            ans.push_back(temp);
            return;
        }

        string s = mapping[digits[index]-'0'];
        for(int i=0;i<s.length();i++){
            temp = temp + s[i];
            solve(digits,mapping,ans,temp,index+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0){
            return {};
        }
        vector<string>ans;
        vector<string> mapping = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string temp;
        solve(digits, mapping, ans, temp, 0);
        return ans;
    }
};
