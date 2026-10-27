class Solution {
public:
    vector<vector<int>> memo;
    int dfs(int i, int j, int rows, int cols){
        if( !((i>=0 && i<rows) && (j>=0 && j<cols)) ){
            return 0;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        if(i == rows-1 && j == cols-1){
            return 1;
        }

        int total = 0;

        //down
        total += dfs(i+1, j, rows, cols);
        //right
        total += dfs(i, j+1, rows, cols);


        memo[i][j] = total;
        return total;
    }
    int uniquePaths(int m, int n) {
        int i = 0;
        int j = 0;
        memo.assign(m, vector<int>(n, -1));
        return dfs(i, j, m, n);

    }
};
