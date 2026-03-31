class Solution {
public:
    void bfs(vector<vector<int>>& grid,queue<pair<int,int>>& q,int& rows,int& cols,int& res){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if(i==-1 && j==-1){
            res++;
            if(!q.empty()){
                q.push({-1,-1});
            }
            return;
        }

        //UP
        if((i-1>=0 && i-1<rows) && (j>=0 && j<cols) && grid[i-1][j]==1){
            grid[i-1][j]=2;
            q.push({i-1,j});
        }

        //DOWN
        if((i+1>=0 && i+1<rows) && (j>=0 && j<cols) && grid[i+1][j]==1){
            grid[i+1][j]=2;
            q.push({i+1,j});
        }

        //LEFT
        if((i>=0 && i<rows) && (j-1>=0 && j-1<cols) && grid[i][j-1]==1){
            grid[i][j-1]=2;
            q.push({i,j-1});
        }

        //RIGHT
        if((i>=0 && i<rows) && (j+1>=0 && j+1<cols) && grid[i][j+1]==1){
            grid[i][j+1]=2;
            q.push({i,j+1});
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int res = -1;

        queue<pair<int,int>> q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        q.push({-1,-1});

        while(!q.empty()){
            bfs(grid,q,rows,cols,res);
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return res;
    }
};
