class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j,int rows,int cols,int& tempRes){
        //UP
        if((i-1>=0&&i-1<rows) && (j>=0&&j<cols) && grid[i-1][j]==1){
            tempRes++;
            grid[i-1][j]=0;
            dfs(grid,i-1,j,rows,cols,tempRes);
        }
    
        //DOWN
        if((i+1>=0&&i+1<rows) && (j>=0&&j<cols) && grid[i+1][j]==1){
            tempRes++;
            grid[i+1][j]=0;
            dfs(grid,i+1,j,rows,cols,tempRes);
        }

        //LEFT
        if((i>=0&&i<rows) && (j-1>=0&&j-1<cols) && grid[i][j-1]==1){
            tempRes++;
            grid[i][j-1]=0;
            dfs(grid,i,j-1,rows,cols,tempRes);
        }

        //RIGHT
        if((i>=0&&i<rows) && (j+1>=0&&j+1<cols) && grid[i][j+1]==1){
            tempRes++;
            grid[i][j+1]=0;
            dfs(grid,i,j+1,rows,cols,tempRes);
        }

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int tempRes = 0;

        int rows=grid.size();
        int cols=grid[0].size();

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    tempRes++;
                    grid[i][j]=0;
                    dfs(grid,i,j,rows,cols,tempRes);
                    res = max(res,tempRes);
                    tempRes=0;
                }
            }
        }
        return res;
    }
};
