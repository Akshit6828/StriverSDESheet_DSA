#include <bits/stdc++.h> 
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    int k = m + n - 1;
    int i = m - 1;
    int j = n - 1;
    
    while(j >= 0){ // We need to iterate until the smaller array (arr2) is not empty.
        if(i >= 0 && arr1[i]  > arr2[j]){ // if arr1 is bigger, insert it into end and decrement arr1 index
            arr1[k] = arr1[i];
            k--;
            i--;
        }else{ //  if arr2 is bigger, insert it into end.. and decrement arr2 index.
            arr1[k] = arr2[j];
            k--;
            j--;
        }
    }
    
    return arr1;
    
    
}