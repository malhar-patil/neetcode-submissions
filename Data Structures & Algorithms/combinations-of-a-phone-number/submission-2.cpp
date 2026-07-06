class Solution {
public:
    void dfs(int index, string& digits, vector<string>& nums, string temp, vector<string>& res){
        if(index >= digits.length()){
            res.push_back(temp);
            return;
        }

        int digit = digits[index] - '0';
        for(int i=0;i<nums[digit].length();i++){
            temp += nums[digit][i];
            dfs(index+1, digits, nums, temp, res);
            temp.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0){
            return {};
        }
        vector<string> nums{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int index = 0;
        string temp = "";
        vector<string> res;
        dfs(index, digits, nums, temp, res);
        return res;
    }
};
