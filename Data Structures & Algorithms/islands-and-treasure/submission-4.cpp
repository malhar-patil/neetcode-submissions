class Solution {
public:
    void bfs(int rows, int cols, queue<pair<int, int>>&q, vector<vector<int>>& grid){
        pair<int, int>p=q.front();
        q.pop();
        int i=p.first;
        int j=p.second;
        int val = grid[i][j];

        //up
        if(i-1>=0 && grid[i-1][j] == INT_MAX){
            grid[i-1][j] = val+1;
            q.push({i-1, j});
        }

        //down
        if(i+1<rows && grid[i+1][j] == INT_MAX){
            grid[i+1][j] = val+1;
            q.push({i+1, j});
        }

        //left
        if(j-1 >=0 && grid[i][j-1] == INT_MAX){
            grid[i][j-1] = val+1;
            q.push({i, j-1});
        }

        //right
        if(j+1<cols && grid[i][j+1] == INT_MAX){
            grid[i][j+1] = val+1;
            q.push({i, j+1});
        }


    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            bfs(rows, cols, q, grid);
        }

        return;

    }
};
