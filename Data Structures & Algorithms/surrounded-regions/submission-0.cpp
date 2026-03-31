class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j , int rows, int cols){
        //UP
        i = i-1;
        if((i>=0 && i<rows) && (j>=0 && j<cols) && board[i][j]=='O'){
            board[i][j] = '#';
            dfs(board,i,j,rows,cols);
        }
        i++;

        // DOWN
        i = i+1;
        if((i>=0 && i<rows) && (j>=0 && j<cols) && board[i][j]=='O'){
            board[i][j] = '#';
            dfs(board,i,j,rows,cols);
        }
        i--;

        //LEFT
        j = j-1;
        if((i>=0 && i<rows) && (j>=0 && j<cols) && board[i][j]=='O'){
            board[i][j] = '#';
            dfs(board,i,j,rows,cols);
        }
        j++;

        //RIGHT
        j = j+1;
        if((i>=0 && i<rows) && (j>=0 && j<cols) && board[i][j]=='O'){
            board[i][j] = '#';
            dfs(board,i,j,rows,cols);
        }
        j--;
    }
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        // for(int i=0;i<rows;i++){
        //     for(int j=0;j<cols;j++){
        //         if(board[i][j]=='O'){
        //             board[i][j] = '#';
        //             dfs(board, i, j, rows, cols);
        //         }
        //     }
        // }

        // first and last row
        for(int i=0;i<rows;i++){
            if(board[i][0]=='O'){
                board[i][0]='#';
                dfs(board,i,0,rows,cols);
            }
            if(board[i][cols-1]=='O'){
                board[i][cols-1]='#';
                dfs(board,i,cols-1,rows,cols);  
            }
        }

        // first and last column
        for(int j=0;j<cols;j++){
            if(board[0][j]=='O'){
                board[0][j]='#';
                dfs(board,0,j,rows,cols);
            }  
            if(board[rows-1][j]=='O'){
                board[rows-1][j]='#';
                dfs(board,rows-1,j,rows,cols);  
            }
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]=='O'){board[i][j]='X';}
                if(board[i][j]=='#'){board[i][j]='O';}
            }
        }
        return;
    }
};
