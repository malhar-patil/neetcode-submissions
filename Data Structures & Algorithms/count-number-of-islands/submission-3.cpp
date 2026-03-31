class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j,int rows, int cols){
        //UP
        if((i-1>=0&&i-1<rows) && (j>=0 && j<cols) && grid[i-1][j]=='1'){
            grid[i-1][j]='0';
            dfs(grid,i-1,j,rows,cols);
        }

        //DOWN
        if((i+1>=0&&i+1<rows) && (j>=0 && j<cols) && grid[i+1][j]=='1'){
            grid[i+1][j]='0';
            dfs(grid,i+1,j,rows,cols);
        }

        //LEFT
        if((i>=0&&i<rows) && (j-1>=0 && j-1<cols) && grid[i][j-1]=='1'){
            grid[i][j-1]='0';
            dfs(grid,i,j-1,rows,cols);
        }

        //RIGHT
        if((i>=0&&i<rows) && (j+1>=0 && j+1<cols) && grid[i][j+1]=='1'){
            grid[i][j+1]='0';
            dfs(grid,i,j+1,rows,cols);
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int rows=grid.size();
        int cols=grid[0].size();

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    res++;
                    grid[i][j]='0';
                    dfs(grid,i,j,rows,cols);
                }
            }
        }
        return res;
    }
};
