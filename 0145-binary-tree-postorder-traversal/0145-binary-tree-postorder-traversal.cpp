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
    vector<int> ans;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        rec(root);
        return ans;
    }
    
    void rec(TreeNode* root) {
        if(!root) return;
        if(root->left)
            rec(root->left);  
        if(root->right)
            rec(root->right);
        
        ans.push_back(root->val);
    }
};