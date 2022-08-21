class Solution {
public:
    void findCombination(int ind , int n, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans, int sum){
        
        /*
        We can also add another base case if we have all elements of array as positive only.
        if(arr[ind] > sum)
            return;
        */
        if(ind == n){ // Tt means we have reached the next to the last element and it must be handeled here.
            if(sum == 0){
                ans.push_back(ds);
                cout<<"Pushed"<<endl;
            }
             return;
        }
        
        if(arr[ind] <= sum){ // It means we can include any occurence of this arr[ind] in our ans
            ds.push_back(arr[ind]);
            findCombination(ind, n, arr, ds, ans, sum - arr[ind]); // Taking Condition (Taking the current index and remaning it here only)
        ds.pop_back(); // Backtracking it and removing it again so it may try the right side branch    
        }
        
        findCombination(ind+1, n, arr, ds, ans, sum);
        
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> ds;
        int n = candidates.size();
        
        findCombination(0, n,candidates, ds, ans, target);
        return ans;
        
    }
};