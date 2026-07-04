class Solution {
public:
    bool res = false;
    void dfs(int i, int j, vector<vector<char>>& board, string word, string temp,vector<vector<int>>& visited){
        if(i >= board.size() || j >= board[0].size() || temp.length() > word.length()){
            return;
        }
        if(temp + board[i][j]== word){
            res = true;
            return;
        }

        visited[i][j] = 1;

        //up
        if(i-1 < board.size() && j < board[0].size() && visited[i-1][j] == -1){
            dfs(i-1, j, board, word, temp+board[i][j], visited);
        }
        //down
        if(i+1 < board.size() && j < board[0].size() && visited[i+1][j] == -1){
            dfs(i+1, j, board, word, temp+board[i][j], visited);
        }
        //left
        if(i < board.size() && j-1 < board[0].size() && visited[i][j-1] == -1){
            dfs(i, j-1, board, word, temp+board[i][j], visited);
        }
        //right
        if(i < board.size() && j+1 < board[0].size() && visited[i][j+1] == -1){
            dfs(i, j+1, board, word, temp+board[i][j], visited);
        }

        visited[i][j] = -1;
        return;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), -1));
        string temp = "";
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == word[0]){
                    dfs(i,j, board, word, temp, visited);
                }
            }
        }
        return res;
    }
};
