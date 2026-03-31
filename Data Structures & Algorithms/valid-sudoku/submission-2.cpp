class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        // row check
        for(int i=0;i<row;i++){
            vector<bool> v1(10, false); 
            for(int j=0;j<col;j++){
                if(board[i][j]=='.'){
                    continue;
                }
                if(v1[(board[i][j]-'0')]==true){
                    return false;
                }
                else{
                    v1[(board[i][j]-'0')]=true;
                }
            }
        }

        // column check 
        for(int j=0;j<col;j++){
            vector<bool> v2(10, false); 
            for(int i=0;i<row;i++){
                if(board[i][j]=='.'){
                    continue;
                }
                if(v2[(board[i][j]-'0')] == true){
                    return false;
                }
                else{
                    v2[(board[i][j]-'0')] = true;
                }
            }
        }

        // 3x3 check //i/3 * 3 + j/3;
        unordered_map<int,vector<bool>> m;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='.'){
                    continue;
                }
                int section = ((i/3)*3) + (j/3);
                if(m.find(section) == m.end()){
                    vector<bool> temp(10,false);
                    temp[(board[i][j]-'0')] = true;
                    m[section] = temp;
                }
                else if(m[section][(board[i][j]-'0')]==true){
                    return false;
                }
                else{
                    m[section][(board[i][j]-'0')] = true;
                }
            }
        }
        return true;

    }
};
