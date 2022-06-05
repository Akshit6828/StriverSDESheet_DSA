/*
Idea's

1. Use sort(). // nlogn
2. Use counting sort. // O(n) time and O(1) space.
3. Use swapping (using three pointers). // O(n) time and O(1) space.
Code idea:

Use low(for last 0), mid(for last 1), and high as three pointers.
Loop until while(mid <= high).
Always have if conditions for mid pointer ONLY.

If we encounter, 2 : swap high with mid.

If we encounter, 1 : swap low with mid..
If we encounter 0 : swap low with mid and increment low++ and mid++.

*/

void sort012(int *arr, int n)
{
   //   Write your code here
    int low = 0, mid = 0, high = n-1;
    
    // 2 2 1 0 1 2 1
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            swap(arr[mid], arr[low]);
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}