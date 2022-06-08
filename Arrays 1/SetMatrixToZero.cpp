/*
LC:https://leetcode.com/problems/set-matrix-zeroes/

*/


#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix){
	// Write your code here.
    
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    int commonElement = 1;
    
    // Making row-1 and col-1 as dummy signal arrays.
    for(int row = 0;row < rows ; row++){
        if(matrix[row][0] == 0) // Checking if there is any zero value in first column of matrix. If yes then marking the commonElement variable as 0;
            commonElement = 0;
         // Traversing from 2nd col to last as 1st col is checked in above condition only.
        for(int col = 1; col < cols ; col++){
            if(matrix[row][col] == 0){
                matrix[row][0] = 0;
                matrix[0][col] = 0;
            }
        }
    }
    
    for(int i = rows - 1 ; i >= 0 ; i--){
        for(int j = cols - 1; j >= 1 ; j--){
            if(matrix[i][0] == 0 || matrix[0][j] == 0) // Checking if any signal element is 0 or not.
                matrix[i][j] = 0; 
        }
        if(commonElement == 0) // If common element gets 0, It means the entire 1st column will be zero. Thus setting the current row's and 0th col as 0 in this case.
            matrix[i][0] = 0;
    }

}