class Solution {
public:
    void dfs(int index, string temp, vector<string>& arr, string digits, vector<string>&res){
        if(index >= digits.size()){
            if(temp.length() > 0)
            res.push_back(temp);
            
            return;
        }
        int digit = digits[index];
        int num = digit-'0';
        for(int i=0;i<arr[num].size();i++){
            dfs(index+1, temp + arr[num][i], arr,  digits, res);
        }


    }
    vector<string> letterCombinations(string digits){
        vector<string> arr = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string>res;
        string temp;
        int index = 0;
        dfs(index, temp, arr, digits, res);
        return res;
    }
};
