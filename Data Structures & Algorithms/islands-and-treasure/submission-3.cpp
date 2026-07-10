class Solution {
public:
    void bfs(vector<vector<int>>& grid, int r, int c, queue<pair<int, int>>& q){
        int rows = grid.size();
        int cols = grid[0].size();
        int val = grid[r][c];

        //up
        if((r-1>=0 && r-1<rows) && (c>=0 && c<cols) && grid[r-1][c] == INT_MAX){
            grid[r-1][c] = val+1;
            q.push({r-1,c});
            //visited.insert({r-1, c});
        }

        //down
        if((r+1>=0 && r+1<rows) && (c>=0 && c<cols) && grid[r+1][c] == INT_MAX){
            grid[r+1][c] = val+1;
            q.push({r+1,c});
            //visited.insert({r+1, c});
        }

        //left
        if((r>=0 && r<rows) && (c-1>=0 && c-1<cols) && grid[r][c-1] == INT_MAX){
            grid[r][c-1] = val+1;
            q.push({r,c-1});
            //visited.insert({r, c-1});
        }

        //right
        if((r>=0 && r<rows) && (c+1>=0 && c+1<cols) && grid[r][c+1] == INT_MAX){
            grid[r][c+1] = val+1;
            q.push({r,c+1});
            //visited.insert({r, c+1});
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        //unordered_set<pair<int,int>> visited;
        queue<pair<int, int>> q;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                    //visited.insert({i,j});
                }
            }
        }

        cout<<q.size()<<endl;

        while(!q.empty()){
            pair<int,int> p= q.front();
            bfs(grid, p.first, p.second, q);
            q.pop();
        }
    }
};
