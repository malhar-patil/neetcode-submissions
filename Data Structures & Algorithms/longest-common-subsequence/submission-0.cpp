class Solution {
public:
    int longestCommonSubsequence(string text1, string text2){
        vector<vector<int>> memo;
        int len1 = text1.length();
        int len2 = text2.length();

        memo.assign(len1+1, vector<int>(len2+1, -1));
        for(int j=0;j<len2+1;j++){
            memo[0][j] = 0;
        }

        for(int i=0;i<len1+1;i++){
            memo[i][0] = 0;
        }

        for(int i=1;i<len1+1;i++){
            for(int j=1;j<len2+1;j++){
                if(text1[i-1] == text2[j-1]){
                    memo[i][j] = 1 + memo[i-1][j-1];
                }
                else{
                    memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
                }
            }
        }

        // for(int i=0;i<len1+1;i++){
        //     for(int j=0;j<len2+1;j++){
        //         cout<<memo[i][j]<<" ";
        //     }cout<<endl;
        // }

        return memo[len1][len2];

    }
};