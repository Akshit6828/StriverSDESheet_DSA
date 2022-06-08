#include <bits/stdc++.h> 
/*

Observations and intution:

If we know the max_subarray sum at i index. We can computer the max_subarray sum at ith index by either 2 choices ie.. a) to include the ith element (if it increases the subarray sum or its positive) or b) not to include the ith element in subarray sum (if it decreases the subarray sum or its negative).
Thus, max subarray sum can be 0.(Not necessary but here in the question.
So, consider taking the first element as the subarray sum.
maxSubArray(i) = max(maxSubArray(i-1) + i, maxSubArray(i));
Thus, maxSumTillCurrentIndex = max( maxSumTillCurrentIndex + currentIndex, maxSumTillCurrentIndex);
Store the MAXEST of all maxSumTillCurrentIndex by doing result = max(result, maxSumTillCurrentIndex).
return result;

*/


long long maxSubarraySum(int arr[], int n)
{  
    long long max_sum_ending_with_current_index = arr[0];
    long long max_possible_sum = INT_MIN; // at worst constrains, the min sum can be INT_MIN;
        
        for(int i = 1; i < n ; i++){
            long long cur_element = arr[i];
            max_sum_ending_with_current_index = max(max_sum_ending_with_current_index + cur_element, cur_element);
            max_possible_sum = max(max_possible_sum, max_sum_ending_with_current_index);
        }
    return max_possible_sum > 0 ?  max_possible_sum : 0 ;
}