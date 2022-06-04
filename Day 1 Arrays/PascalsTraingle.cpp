#include <bits/stdc++.h> 
/*
Variations these questions can be asked:

Print first n rows of a pascal triangle.
Print the n th row of the pascal triangle.
Print the element at the rth row and cth column in pascal traingle.
Pascal triangle in 2D Array Looks like:
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
....

Observation for Pascal Traingle:

Every ith row(0 based indexing) has i+1 items. Row 0 has 1 item, 1 has 2 items, 2 have 3 items.....
First and last element of each row is 1.
Element at (r,c) index (O based indexing)= r C c
Example: x[4][2] = 4C2 = 4! / ( 2 ! . 2 ! ) --> ( 4 . 3 ) / 2 ! --> 6
In 2D Array, x[row][col] = x[row-1][col-1] + x[row-1][col].
Time Complexity Analysis Key Points:

nCr can be computed for any element in O(n).
Printing ith row only in pascal traingle is O(N* N).
Complexity Analysis for each variation:

Variation 1: TC: O(N.N) and SC: O( N.N) as we are storing the entire pascal triangle.
Variation 2: TC: O(N) and SC: O(N) as we are storing the entire row.

*/
vector<vector<long long int>> printPascal(int n) {
    
    vector<vector<long long int>> triangle(n);
    for(int i = 0;i < n; i++){
        triangle[i].resize(i+1);
        triangle[i][0] = triangle[i][i] = 1; // Adding 1 to first and last index
// No need to decrement triangle[i][i-1] as we are already taking 0 based indexing. Thus,3rd row = T[2] and T[2][0] = T[2][2].
        
        //Traversing from 1st column to 2nd last column
        for(int j = 1; j < i ; j++)
            triangle[i][j] = triangle[i-1][j] + triangle[i-1][j-1];
        
    }
    
    return triangle;
    

}
