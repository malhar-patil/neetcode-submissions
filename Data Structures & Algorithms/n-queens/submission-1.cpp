class Solution {
public:
    bool isPossible(int i,int j, int rows, int cols, vector<string>&temp){
        //check row
        for(int c=0;c<cols;c++){
            if(temp[i][c] == 'Q'){
                return false;
            }
        }

        //check col
        for(int r=0;r<rows;r++){
            if(temp[r][j] == 'Q'){
                return false;
            }
        }

        int r = i;
        int c = j;

        while( r-1 >= 0 && c-1 >= 0){
            r--;
            c--;
        }

        //check diagonal 
        while(r<rows && c<cols){
            if(temp[r][c] == 'Q'){
                return false;
            }
            r++;
            c++;
        }
        r = i;
        c = j;
        while(r-1 >= 0 && c+1 < cols){
            r--;
            c++;
        }
        while(r < rows  && c>=0){
            if(temp[r][c] == 'Q'){
                return false;
            }
            r++;
            c--;
        }
        return true;

    }
    void dfs(int i, int j, int rows, int cols, vector<string>temp, vector<vector<string>>& res){
        if(!((i>=0 && i<rows) && (j>=0 && j<cols))){
            res.push_back(temp);
            return;
        }
        for(int c=0;c<cols;c++){
            if(isPossible(i, c, rows, cols, temp)){
                temp[i][c] = 'Q';
                dfs(i+1, j, rows, cols, temp, res);
                temp[i][c] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        string s(n, '.');
        vector<string> temp(n, s);

        int rows = n;
        int cols = n;

        int i=0;
        int j=0;

        dfs(i, j, rows, cols, temp, res);
        return res;
    }
};
