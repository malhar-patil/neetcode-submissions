class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int res=0;
        queue<pair<int,int>> q;
        bool isChanged=false;
        int rows=grid.size();
        int cols=grid[0].size();

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        q.push({-1,-1});

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(i==-1 && j==-1 && isChanged){
                isChanged=false;
                res++;
                if(!q.empty()){
                    q.push({-1,-1});
                }
                continue;
            }
            else if(i==-1 && j==-1 && !isChanged){
                continue;
            }
            //UP
            if((i-1>=0 && i-1<rows) && (j>=0 && j<cols) && grid[i-1][j]==1){
                grid[i-1][j]=2;
                q.push({i-1,j});
                isChanged=true;
                // cout<<i-1<<" "<<j<<endl;
            }

            //DOWN
            if((i+1>=0 && i+1<rows) && (j>=0 && j<cols) && grid[i+1][j]==1){
                grid[i+1][j]=2;
                q.push({i+1,j});
                isChanged=true;
                // cout<<i+1<<" "<<j<<endl;
            }

            //LEFT
            if((i>=0 && i<rows) && (j-1>=0 && j-1<cols) && grid[i][j-1]==1){
                grid[i][j-1]=2;
                q.push({i,j-1});
                isChanged=true;
                // cout<<i<<" "<<j-1<<endl;
            }

            //RIGHT
            if((i>=0 && i<rows) && (j+1>=0 && j+1<cols) && grid[i][j+1]==1){
                grid[i][j+1]=2;
                q.push({i,j+1});
                isChanged=true;
                // cout<<i<<" "<<j+1<<endl;
            }

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
