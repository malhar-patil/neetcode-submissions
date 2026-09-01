class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        //check rows
        int c = 0;
        while(c < cols){
            vector<int> rowCheck(10,0);
            for(int r=0;r<rows;r++){
                if(board[r][c] == '.'){continue;}
                int value = (board[r][c]) - '0';
                if(rowCheck[value] == 1){
                    return false;
                }
                rowCheck[value] = 1;
            }
            c++;
        }

        //check cols
        int r = 0;
        while(r < rows){
            vector<int> colCheck(10,0);
            for(int c=0;c<rows;c++){
                if(board[r][c] == '.'){continue;}
                int value = (board[r][c]) - '0';
                if(colCheck[value] == 1){
                    return false;
                }
                colCheck[value] = 1;
            }
            r++;
        }

        // //check squares
        unordered_map<int, unordered_set<int>> m;
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(board[r][c] == '.'){continue;}
                int block = (r/3)*3 + (c/3);
                int value = (board[r][c]) - '0';
                if(m[block].contains(value)){
                    return false;
                }
                m[block].insert(value);
            }
        }

        return true;
    }
};
