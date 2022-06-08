#include <bits/stdc++.h> 
/*
Brute Force:

Sort the array in ascending order.Generate all the permutations and print the next required.
TC:O(N! * N) -> N! (for generating all orders) and N (to traverse)
SC: O(N! * N)
Optimization:
Algorithm Steps:

Traverse from reverse and find first index where x[i] < x [i+1] (first minima). (Eg: ind1).
Again traverse from back and find the first index from back which is having greater value than x[ind2].
Swap(x[ind1], ind[2]).
Reverse(ind1 + 1, end).
Intution behind the algorithm
The intution lies in the dictionary order.

1   2   3
        <-
1   3   2

2   1   3
2   3   1
3   1   2
3   2   1

smallest_   secondsmall_  thirdsmall_
smallest_   swap(second_small, third_small_)
....
....
More suitable example:
1 2 3 4 
1 2 4 3 // swapping the "largest" with "second largest" on right hand side and "smallest" with "2nd non occured smallest" on left hand side.
1 3 2 4
1 4 2 3
......
......
Behaviour of Problem:

Always swap the largest with second largest on right hand side to
Whenever we write some permutation, its always an increasing sequence from the back.
Try to keep left index as smallest possible which hasnt occured earlier.
*/

vector<int> nextPermutation(vector<int> &nums, int n)
{
    //  Write your code here.
    int breakPoint = -1, nextGreater = -1;
    vector<int> next_permutation;
        
        for(int i = nums.size() - 2; i >=0 ; i--){
            if(nums[i] < nums[i+1] ){
                breakPoint = i;
                break;
            }
        }
        
        if(breakPoint!= -1){ // Found a breakpoint such that nums[i] < nums[i+1]
            // In this case nextGreater element will be found for sure as there is atleast something to the right of breakPoint which is greater thats only due to this, the condition in 7th line made it true.
            
            for(int i = nums.size() - 1; i>=0; i--){
                if(nums[i] > nums[breakPoint]){ // Note: nums[i] >= nums[breakPoint] wont work as for case: [1,5,1] it will generate: {1,1,5}(Swaping mid 5 with last 1) but the actual output should be: {5,1,1}. (swapping 5 with first 1)
                    nextGreater = i;
                    break;
                }
            }
            
            swap(nums[breakPoint], nums[nextGreater]);
            reverse(nums.begin() + breakPoint + 1 , nums.end());
        }
        else{ // The array is sorted descending: ie no breakpoint is found.
            reverse(nums.begin(), nums.end());
        }
    
    next_permutation = nums;
    return next_permutation;
        
}