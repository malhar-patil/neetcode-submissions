class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i , int j, int& area){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j] == 0){
            return;
        }

        grid[i][j] = 0;
        area++;

        //up
        dfs(grid, i-1, j, area);
        //down
        dfs(grid, i+1, j, area);
        //right
        dfs(grid, i, j+1, area);
        //left
        dfs(grid, i, j-1, area);
    }   
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    int area = 0;
                    dfs(grid, i, j, area);
                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
    }
};
