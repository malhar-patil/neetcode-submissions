class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()){
            return false;
        }
        int m = s1.length();
        int n = s2.length();

        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        dp[m][n] = true;


        for(int j=n-1;j>=0;j--){
            dp[m][j] = dp[m][j+1] && s2[j] == s3[m+j];
        }

        for(int i=m-1;i>=0;i--){
            dp[i][n] = dp[i+1][n] && s1[i] == s3[n+i];
        }

        for(int i=dp.size()-2;i>=0;i--){
            for(int j=dp[0].size()-2;j>=0;j--){
                dp[i][j] = (dp[i+1][j] && s1[i] == s3[i+j]) || (dp[i][j+1] && s2[j] == s3[i+j]);
            }
        }

        // for(int i=0;i<dp.size();i++){
        //     for(int j=0;j<dp[0].size();j++){
        //         cout<<dp[i][j]<<" ";
        //     }cout<<endl;
        // }

        return dp[0][0];
    }
};