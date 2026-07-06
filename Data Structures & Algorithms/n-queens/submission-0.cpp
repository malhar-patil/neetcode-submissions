class Solution {
public:
    bool row(int r, int placedR, int placedC, int n, vector<vector<int>>& lookup){
        for(int c = 0; c<n; c++){
            if(c == placedC){
                continue;
            }
            if(lookup[r][c] == 1){
                return false;
            }
        }
        return true;
    }
    bool col(int c, int placedR, int placedC, int n, vector<vector<int>>& lookup){
        for(int r = 0; r<n; r++){
            if(r == placedR){
                continue;
            }
            if(lookup[r][c] == 1){
                return false;
            }
        }
        return true;
    }

    bool diag1(int placedR, int placedC, int n,vector<vector<int>>& lookup){
        int r = placedR - 1;
        int c = placedC - 1;

        while(r >=0 && c >=0){
            if(lookup[r][c] == 1){
                return false;
            }
            r--;
            c--;
        }

        r = placedR + 1;
        c = placedC + 1;
        while(r <n  && c < n){
            if(lookup[r][c] == 1){
                return false;
            }
            r++;
            c++;
        }

        return true;

    }

    bool diag2(int placedR, int placedC, int n,vector<vector<int>>& lookup){
        int r = placedR - 1;
        int c = placedC + 1;

        while(r >=0 && c < n){
            if(lookup[r][c] == 1){
                return false;
            }
            r--;
            c++;
        }

        r = placedR + 1;
        c = placedC - 1;
        while(r < n  && c >= 0){
            if(lookup[r][c] == 1){
                return false;
            }
            r++;
            c--;
        }

        return true;
    }

    void traverse(int r,vector<vector<int>> lookup, vector<string> arr,vector<vector<string>>& res, int n){
        if(r >= n){
            res.push_back(arr);
            return;
        }


        for(int c = 0;c<n;c++){
            if(row(r, r, c, n, lookup) && col(c, r, c, n, lookup) && diag1(r, c, n, lookup) && diag2(r, c, n, lookup)){
                lookup[r][c] = 1;
                arr[r][c]= 'Q';
                traverse(r+1, lookup, arr, res, n);
                lookup[r][c] = 0;
                arr[r][c] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<vector<int>> lookup(n, vector<int>(n, 0));
        vector<string> arr(n, string(n , '.'));
        traverse(0, lookup, arr, res, n);
        return res;
    }
};