class Solution {
public:
    void bfs(vector<vector<int>>& grid, int rows, int cols,queue<pair<int,int>>& q){
        int i = q.front().first;
        int j = q.front().second;
        int val = grid[i][j];

        //UP
        if((i-1>=0 && i-1<rows) && (j>=0&&j<cols) && grid[i-1][j]==INT_MAX){
            grid[i-1][j] = val+1;
            q.push({i-1,j});
        }

        //DOWN
        if((i+1>=0 && i+1<rows) && (j>=0&&j<cols) && grid[i+1][j]==INT_MAX){
            grid[i+1][j] = val+1;
            q.push({i+1,j});
        }

        //LEFT
        if((i>=0 && i<rows) && (j-1>=0&&j-1<cols) && grid[i][j-1]==INT_MAX){
            grid[i][j-1] = val+1;
            q.push({i,j-1});
        }

        //RIGHT
        if((i>=0 && i<rows) && (j+1>=0&&j+1<cols) && grid[i][j+1]==INT_MAX){
            grid[i][j+1] = val+1;
            q.push({i,j+1});
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        queue<pair<int,int>>q;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            bfs(grid,rows,cols,q);
            q.pop();
        }   
        return;     
    }
};
