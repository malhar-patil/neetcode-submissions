class Solution {
public:
    
    bool solve(vector<vector<char>>& board, string word,int i ,int j , int rows,int cols){
        if(word.length()==0){
            return true;
        }
        if((i<0 || i>=rows) || (j<0 || j>=cols)){
            return false;
        }
        if(board[i][j]!=word[0]){
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '#';
        bool res = (
            solve(board,word.substr(1),i,j-1,rows,cols) ||
            solve(board,word.substr(1),i,j+1,rows,cols) ||
            solve(board,word.substr(1),i-1,j,rows,cols) ||
            solve(board,word.substr(1),i+1,j,rows,cols));
        board[i][j] = temp;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]==word[0]){
                    if(solve(board,word,i,j,rows,cols)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};