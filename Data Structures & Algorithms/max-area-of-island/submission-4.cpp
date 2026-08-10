class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& grid, int& area, int& tempArea, int& rows, int& cols){
    // if(!(r>=0 && r<rows && c>=0 && c<cols)){
    //     return;
    // }

    grid[r][c] = 0;
    tempArea++;
    //up
    if(((r-1>=0 && r-1<rows && c>=0 && c<cols)) && grid[r-1][c] == 1){
        dfs(r-1, c, grid, area, tempArea, rows, cols);
    }

    //down
    if(((r+1>=0 && r+1<rows && c>=0 && c<cols)) && grid[r+1][c] == 1){
        dfs(r+1, c, grid, area, tempArea, rows, cols);
    }

    //left
    if(((r>=0 && r<rows && c-1>=0 && c-1<cols)) && grid[r][c-1] == 1){
        dfs(r, c-1, grid, area, tempArea, rows, cols);
    }

    //right
    if(((r>=0 && r<rows && c+1>=0 && c+1<cols)) && grid[r][c+1] == 1){
        dfs(r, c+1, grid, area, tempArea, rows, cols);
    }

    area = max(tempArea, area);
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;
        int tempArea = 0;

        int rows = grid.size();
        int cols = grid[0].size();

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 1){
                    dfs(i,j,grid, area, tempArea, rows, cols);
                    tempArea = 0;
                }
            }
        }
        return area;
    }
};
