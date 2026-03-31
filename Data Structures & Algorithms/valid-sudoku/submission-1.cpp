class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        

        int rows = board.size();
        int cols = board[0].size();

        for(int i=0;i<rows;i++){
            unordered_map<int,bool> m1;
            for(int j=0;j<cols;j++){
                if(board[i][j]=='.'){
                    continue;
                }
                if(m1.find(board[i][j]-48)!=m1.end()){
                    return false;
                }
                else{
                    m1[board[i][j]-48] = true;
                }
            }
        }

        for(int j=0;j<cols;j++){
            unordered_map<int,bool> m2;
            for(int i=0;i<rows;i++){
                if(board[i][j]=='.'){
                    continue;
                }
                if(m2.find(board[i][j]-48)!=m2.end()){
                    return false;
                }
                else{
                    m2[board[i][j]-48] = true;
                }
            }
        }

        unordered_map<int,vector<bool>> m3;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]=='.'){
                    continue;
                }
                int index = ((i/3)*3)+(j/3);
                if(m3.find(index) == m3.end()){
                    m3[index] = vector<bool>(10,false);
                }

                if(m3[index][board[i][j]-48] == true){
                    return false;
                }

                m3[index][board[i][j]-48] = true;
            }
        }
        return true;
    }
};
