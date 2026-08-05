class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& grid, int rows, int cols){
        if(!(r>=0 && r<rows && c>=0 && c<cols)){
            return;
        }
        grid[r][c] = '0';

        //up
        if((r-1>=0 && r-1<rows && c>=0 && c<cols) && grid[r-1][c] == '1' ){
            dfs(r-1,c,grid, rows, cols);
        }
        //down
        if((r+1>=0 && r+1<rows && c>=0 && c<cols) && grid[r+1][c] == '1' ){
            dfs(r+1,c,grid, rows, cols);
        }
        //left
        if((r>=0 && r<rows && c-1>=0 && c-1<cols) && grid[r][c-1] == '1' ){
            dfs(r,c-1,grid, rows, cols);
        }
        //right
        if((r>=0 && r<rows && c+1>=0 && c+1<cols) && grid[r][c+1] == '1' ){
            dfs(r,c+1,grid, rows, cols);
        }

        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int res = 0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == '1'){
                    res++;
                    dfs(i, j, grid, rows, cols);
                }
            }
        }
        return res;
    }
};
