class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();

        int total = row*col;

        int s=0;
        int e=total-1;
        int mid=s+(e-s)/2;

        while(s<=e){
            int i = mid/col;
            int j = mid%col;

            if(matrix[i][j] == target){
                return true;
            }
            else if(matrix[i][j]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return false;
    }
};
