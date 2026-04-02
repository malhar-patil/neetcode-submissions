class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows= matrix.size();
        int cols = matrix[0].size();
        // 90 transpose + reverse rows

        //transpose
        int colLimit = 0;
        for(int i=0; i<rows && colLimit < cols;i++){
            int j = 0;
            while(j <= colLimit){
                swap(matrix[i][j], matrix[j][i]);
                j++;
            }
            colLimit++;
        }

        // reverse rows
        for(int i=0;i<rows;i++){
            int s = 0;
            int e = cols - 1;
            while(s <= e){
                swap(matrix[i][s], matrix[i][e]);
                s++;
                e--;
            }
        }
        return;
    }
};
