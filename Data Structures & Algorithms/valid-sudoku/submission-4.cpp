class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int rows=board.size();
        int cols=board[0].size();

        // row check;
        for(int i=0;i<rows;i++){
            unordered_map<int,bool> m;
            for(int j=0;j<cols;j++){
                if(board[i][j]=='.'){
                    continue;
                }
                if(m.find(board[i][j]-'0')!=m.end()){
                    return false;
                }
                else{
                    m[board[i][j]-'0']=true;
                }
            }
        }

        //col check
        for(int i=0;i<rows;i++){
            unordered_map<int,bool> m;
            for(int j=0;j<cols;j++){
                if(board[j][i]=='.'){
                    continue;
                }
                if(m.find(board[j][i]-'0')!=m.end()){
                    return false;
                }
                else{
                    m[board[j][i]-'0']=true;
                }
            }
        }

        //3x3 check
        unordered_map<int,unordered_map<int,bool>> m;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]=='.'){
                    continue;
                }
                int grp = (i/3)*3 + j/3;
                if(m[grp].find(board[i][j]-'0')!=m[grp].end()){
                    return false;
                }
                else{
                    m[grp][board[i][j]-'0']=true;
                }
            }
        }
        return true;
    }
};
