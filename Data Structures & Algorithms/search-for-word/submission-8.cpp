class Solution {
public:
    bool dfs(int index, int i, int j, int rows, int cols, string&temp, string& word, vector<vector<char>>& board){
        if( !((i>=0 && i<rows) && (j>=0 && j<cols)) || index >= word.length()){
            if(temp == word){
                return true;
            }
            return false;
        }

        if(board[i][j] != word[index]){
            return false;
        }

        temp.push_back(board[i][j]);
        char ch = board[i][j];
        board[i][j] = '-';

        //up
        bool up = dfs(index+1, i-1, j, rows, cols, temp, word, board);

        //down
        bool down = dfs(index+1, i+1, j, rows, cols, temp, word, board);

        //left
        bool left = dfs(index+1, i, j-1, rows, cols, temp, word, board);

        //right
        bool right = dfs(index+1, i, j+1, rows, cols, temp, word, board);

        board[i][j] = ch;
        temp.pop_back();

        return up || down || left || right;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        string temp;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                temp.clear();
                if(board[i][j] == word[0] && dfs(0, i, j, rows, cols,temp, word, board)){
                    return true;
                }
            }
        }
        return false;
    }
};
