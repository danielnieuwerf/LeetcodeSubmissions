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
    set<int> s;

public:
    int findSecondMinimumValue(TreeNode* root) {
        rec(root);
        if(s.size() > 1) {
            std::set<int>::iterator it = s.begin();
            std::advance(it, 1);
            return *it;
        }
        return -1;
    };

    void rec(TreeNode* root) {
        if(!root)
            return;
        s.insert(root->val);
        rec(root->left);
        rec(root->right);
    }
};