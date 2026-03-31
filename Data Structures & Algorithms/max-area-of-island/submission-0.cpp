class Solution {
public:
    void dfs(vector<vector<int>>& grid,int rows,int cols, int i, int j, int & temp){
        //up
        int s = i-1;
        int e = j;
        if((s>=0 && s<rows) && (e>=0 && e<cols)){
            if(grid[s][e]==1){
                grid[s][e]=0;
                temp++;
                dfs(grid,rows,cols,s,e,temp);
            }
        }

        //down
        s = i+1;
        e = j;
        if((s>=0 && s<rows) && (e>=0 && e<cols)){
            if(grid[s][e]==1){
                grid[s][e]=0;
                temp++;
                dfs(grid,rows,cols,s,e,temp);
            }
        }

        //left
        s = i;
        e = j-1;
        if((s>=0 && s<rows) && (e>=0 && e<cols)){
            if(grid[s][e]==1){
                grid[s][e]=0;
                temp++;
                dfs(grid,rows,cols,s,e,temp);
            }
        }

        //right
        s = i;
        e = j+1;
        if((s>=0 && s<rows) && (e>=0 && e<cols)){
            if(grid[s][e]==1){
                grid[s][e]=0;
                temp++;
                dfs(grid,rows,cols,s,e,temp);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int rows=grid.size();
        int cols=grid[0].size();

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    int temp = 1;
                    grid[i][j]=0;
                    dfs(grid,rows,cols,i,j,temp);
                    res=max(res,temp);
                }
            }
        }
        return res;
    }
};
