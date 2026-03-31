class Solution {
public:
    void dfs(vector<vector<int>>& heights, int i, int j, vector<int>& visit, int prevHeight){
        int row = heights.size();
        int col = heights[0].size();
        int index = i*col+j;

        if(i<0 || i>=row || j<0 || j>=col || heights[i][j] < prevHeight || visit[index]==1){
            return;
        }
        visit[index]=1;
        dfs(heights,i-1,j,visit,heights[i][j]);
        dfs(heights,i+1,j,visit,heights[i][j]);
        dfs(heights,i,j-1,visit,heights[i][j]);
        dfs(heights,i,j+1,visit,heights[i][j]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<int> pac(rows*cols,-1);
        vector<int> atl(rows*cols,-1);

        for(int i=0;i<cols;i++){
            dfs(heights,0,i,pac,heights[0][i]);
            dfs(heights,rows-1,i,atl,heights[rows-1][i]);
        }

        for(int i=0;i<rows;i++){
            dfs(heights,i,0,pac,heights[i][0]);
            dfs(heights,i,cols-1,atl,heights[i][cols-1]);
        }

        vector<vector<int>> res;
        for(int i=0;i<pac.size();i++){
            if(pac[i]!=-1 && atl[i]!=-1){
                res.push_back({i/cols,i%cols});
            } 
        }
        return res;
    }
};
