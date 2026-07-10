class Solution {
public:
    void bfs(vector<vector<int>>& grid, int& rows, int& cols, int&time, queue<pair<vector<int>, int>>& q){
        int r = q.front().first[0];
        int c = q.front().first[1];
        int currTime =q.front().second;

        //up
        if((r-1>=0 && r-1<rows) && (c>=0 && c<cols) && grid[r-1][c] == 1){
            q.push({{r-1,c}, currTime+1});
            grid[r-1][c] = 2;
            time = max(time, currTime+1);
        }
        //down
        if((r+1>=0 && r+1<rows) && (c>=0 && c<cols) && grid[r+1][c] == 1){
            q.push({{r+1,c}, currTime+1});
            grid[r+1][c] = 2;
            time = max(time, currTime+1);
        }
        //left
        if((r>=0 && r<rows) && (c-1>=0 && c-1<cols) && grid[r][c-1] == 1){
            q.push({{r,c-1}, currTime+1});
            grid[r][c-1] = 2;
            time = max(time, currTime+1);
        }
        //right
        if((r>=0 && r<rows) && (c+1>=0 && c+1<cols) && grid[r][c+1] == 1){
            q.push({{r,c+1}, currTime+1});
            grid[r][c+1] = 2;
            time = max(time, currTime+1);
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int time = 0;
        queue<pair<vector<int>, int>> q;
        
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(grid[r][c] == 2){
                    q.push({{r,c}, 0});
                }
            }
        }

        while(!q.empty()){
            bfs(grid, rows, cols, time, q);
            q.pop();
        }

        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(grid[r][c] == 1){
                    return -1;
                }
            }
        }
        return time;
    }
};
