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
    void levelOrder(TreeNode*  root,vector<vector<int>> &ans){
        
        if(root == NULL)
            return;
        queue<TreeNode*> q;
        q.push(root);
        
        bool leftToRight = true;
        while(!q.empty()){
            int levelLen = q.size();
            vector<int> level(levelLen);
            for(int i = 0 ; i<levelLen ; i++){
                
                TreeNode* curNode = q.front();
                q.pop();
                int index;
                if(leftToRight)
                    index = i ;
                else 
                    index = (levelLen - i - 1);
                
                level[index] = curNode->val;
                
                if(curNode->left)
                    q.push(curNode->left);
                if(curNode->right)
                    q.push(curNode->right);
                
            }
            cout<<"level.size() = "<<level.size()<<endl;
            ans.emplace_back(level);
            leftToRight = !leftToRight;
        }
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levelOrder(root, ans);
        return ans;
    }
};