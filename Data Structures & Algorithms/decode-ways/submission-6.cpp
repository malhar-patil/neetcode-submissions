class Solution {
public:
    int dfs(int index, string& s, vector<int>& memo){
        if(index >= s.length()){
            return 1;
        }

        if(memo[index] != -1){
            return memo[index];
        }

        int res1 = 0;
        int res2 =0;
        int num1 = s[index] - '0';
        if(num1 != 0){
            res1 = dfs(index+1, s, memo);
        }

        if(index <= s.length()-2){
            int num2 = stoi(s.substr(index, 2));
            if(num2 >= 10 && num2 <= 26){
                res2 = dfs(index+2, s, memo);
            }
        }

        memo[index] = res1+res2;
        cout<<res1+res2<<endl;
        return memo[index];

    }
    int numDecodings(string s) {
        vector<int> memo(s.length(), -1);
        return dfs(0, s, memo);
    }
};
