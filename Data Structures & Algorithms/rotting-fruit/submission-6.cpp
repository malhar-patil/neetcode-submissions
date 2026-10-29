class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>>q;
        int time = 0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        q.push({-1, -1});

        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();

            if(p.first == -1){
                if(!q.empty()){
                    time++;
                    q.push({-1, -1});
                }
                continue;
            }
            int i=p.first;
            int j=p.second;
            //up
            if(i-1 >=0 && grid[i-1][j] == 1){
                grid[i-1][j] = -1;
                q.push({i-1, j});
            }
            //down
            if(i+1 <rows && grid[i+1][j] == 1){
                grid[i+1][j] = -1;
                q.push({i+1, j});
            }
            //left
            if(j-1>=0 && grid[i][j-1] == 1){
                grid[i][j-1] = -1;
                q.push({i, j-1});
            }
            //right
            if(j+1<cols && grid[i][j+1] == 1){
                grid[i][j+1] = -1;
                q.push({i, j+1});
            }
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return time;
    }
};
