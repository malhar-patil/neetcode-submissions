class Solution {
public:
    void dfs(vector<vector<char>>& grid,int rows,int cols,int i,int j,int& res){
        //check up
        int s = i-1;
        int e = j;
        if((s>=0 && s<rows) && (e>=0 && e<cols)){
            if(grid[s][e]=='1'){
                grid[s][e]='0';
                dfs(grid,rows,cols,s,e, res);
            }
        }

        //check down
        s = i+1;
        e = j;
        if((s>=0 && s<rows) && (e>=0 && e<cols)){
            if(grid[s][e]=='1'){
                grid[s][e]='0';
                dfs(grid,rows,cols,s, e, res);
            }
        }

        //check left
        s = i;
        e = j-1;
        if((s>=0 && s<rows) && (e>=0 && e<cols)){
            if(grid[s][e]=='1'){
                grid[s][e]='0';
                dfs(grid,rows,cols,s, e, res);
            }
        }

        //check right
        s = i;
        e = j+1;
        if((s>=0 && s<rows) && (e>=0 && e<cols)){
            if(grid[s][e]=='1'){
                grid[s][e]='0';
                dfs(grid,rows,cols,s, e, res);
            }
        } 
        // //check 
        // res++;
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int rows=grid.size();
        int cols=grid[0].size();

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    dfs(grid, rows,cols,i,j,res);
                    res++;
                }
            }
        }
        return res;
    }
};
