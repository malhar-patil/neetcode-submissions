class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        int startingRow = 0;
        int startingCol = 0;
        int endingRow = matrix.size() - 1;
        int endingCol = matrix[0].size() - 1;

        int cnt = matrix.size() * matrix[0].size();

        while(cnt > 0){
            //first row
            for(int i=startingCol; i<=endingCol && cnt>0;i++){
                res.push_back(matrix[startingRow][i]);
                cnt--;
            }
            startingRow++;

            //last column
            for(int i=startingRow;i<=endingRow && cnt>0;i++){
                res.push_back(matrix[i][endingCol]);
                cnt--;
            }
            endingCol--;

            //last row
            for(int i=endingCol;i>=startingCol && cnt>0;i--){
                res.push_back(matrix[endingRow][i]);
                cnt--;
            }
            endingRow--;

            //first column
            for(int i=endingRow;i>=startingRow && cnt>0;i--){
                res.push_back(matrix[i][startingCol]);
                cnt--;
            }
            startingCol++;
        }
        return res;
    }
};
