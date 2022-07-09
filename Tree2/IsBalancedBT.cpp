/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int validate(TreeNode *root){
        if(root == NULL)
            return 0;
        int leftHeight = validate(root->left);
        int rightHeight = validate(root->right);
        
        if(leftHeight == -1 or rightHeight == -1 or abs(leftHeight - rightHeight) > 1)
            return -1;
   
        else
            return 1 + max(leftHeight,rightHeight);
    }
public:
    bool isBalanced(TreeNode* root) {
        return validate(root) != -1;
    }
};