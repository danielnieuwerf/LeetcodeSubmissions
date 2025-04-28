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
public:
    int diameterOfBinaryTree(TreeNode* root) {
        auto x = 0;
        if(root->left)
            x = max(x, diameterOfBinaryTree(root->left));
        if(root->right)
            x = max(x, diameterOfBinaryTree(root->right));
        return max(maxDepth(root->left) + maxDepth(root->right), x);
    }

    int maxDepth(TreeNode* root){
        if(!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};