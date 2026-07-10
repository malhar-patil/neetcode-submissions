class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<int>>& ocean){
        int rows = heights.size();
        int cols = heights[0].size();
        if(r<0 || r>=rows || c<0 || c>=cols || ocean[r][c] == 1){
            return;
        }

        ocean[r][c] = 1;
        if((r-1>=0 && r-1<rows) && (c>=0 && c<cols) && heights[r-1][c] >= heights[r][c]){
            dfs(r-1, c, heights, ocean);
        }

        if((r+1>=0 && r+1<rows) && (c>=0 && c<cols) && heights[r+1][c] >= heights[r][c]){
            dfs(r+1, c, heights, ocean);
        }

        if((r>=0 && r<rows) && (c-1>=0 && c-1<cols) && heights[r][c-1] >= heights[r][c]){
            dfs(r, c-1, heights, ocean);
        }

        if((r>=0 && r<rows) && (c+1>=0 && c+1<cols) && heights[r][c+1] >= heights[r][c]){
            dfs(r, c+1, heights, ocean);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> pacific(rows, vector<int>(cols, 0));
        vector<vector<int>> atlantic(rows, vector<int>(cols, 0));


        //pacific
        for(int c=0;c<cols;c++){
            dfs(0, c, heights, pacific);
        }
        for(int r=0;r<rows;r++){
            dfs(r, 0, heights, pacific);
        }

        //atlantic
        for(int c=0;c<cols;c++){
            dfs(rows-1, c, heights, atlantic);
        }
        for(int r=0;r<rows;r++){
            dfs(r, cols-1, heights, atlantic);
        }

        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(pacific[r][c] == 1 && atlantic[r][c] == 1){
                    ans.push_back({r,c});
                }
            }
        }
        return ans;
    }
};
