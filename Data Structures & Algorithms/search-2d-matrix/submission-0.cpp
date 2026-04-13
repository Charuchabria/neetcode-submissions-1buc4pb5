class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();

        int top = 0;
        int bot = ROWS - 1; 
        while(top <= bot){
            int m = top + ((bot - top)/2);

            if(target > matrix[m][COLS - 1]){
                top = m + 1; 
            }else if (target < matrix[m][0]){
                bot = m - 1;
            }else {
                int l = 0, r = COLS - 1;
                while(l <= r){
                    int mid2 = l + (r - l) / 2;

                    if(matrix[m][mid2] == target){
                        return true;
                    }
                    else if(matrix[m][mid2] < target){
                        l = mid2 + 1;
                    }
                    else{
                        r = mid2 - 1;
                    }
                }
                return false; 
            }       
        }
        return false;  
    }
};


  