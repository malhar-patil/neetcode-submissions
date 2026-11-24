class Solution {
public:
    vector<vector<int>> memo;
    int dfs(int i, int j, int rows, int cols, vector<vector<int>>& matrix){
        if(memo[i][j] != -1){
            return memo[i][j];
        }

        int num = matrix[i][j];
        
        int up = i-1>=0 && matrix[i-1][j] > num ?  dfs(i-1, j, rows, cols, matrix) : 0;
        int down = i+1<rows && matrix[i+1][j] > num ? dfs(i+1, j, rows, cols, matrix) : 0;
        int left = j-1>=0 && matrix[i][j-1] > num ? dfs(i, j-1, rows, cols, matrix) : 0;
        int right = j+1<cols && matrix[i][j+1] > num ? dfs(i, j+1, rows, cols, matrix) : 0;

        return memo[i][j] = 1 + max({up, down, left, right});
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        memo.assign(rows, vector<int>(cols, -1));
        int res = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                res = max(res, dfs(i, j, rows, cols, matrix));
            }
        }
        return res;
    }
};