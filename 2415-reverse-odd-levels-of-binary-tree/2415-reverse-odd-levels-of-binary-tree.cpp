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
    TreeNode* reverseOddLevels(TreeNode* root) {
        rec({root}, 0);
        return root;
    }
    
    void rec(vector<TreeNode*> nodes, int level) {
        if(nodes.empty())
            return;
        vector<TreeNode*> nextLevel;
        for(auto node: nodes) {
            if(node->left)
                nextLevel.push_back(node->left);
            if(node->right)
                nextLevel.push_back(node->right);
        }
        if(level % 2 == 1) {
            vector<int> values;
            for(auto node: nodes)
                values.push_back(node->val);
            assert(values.size() == pow(2, level));
            for(int i = 0; i<pow(2, level); ++i)
                nodes[i]->val = values[pow(2, level)-1-i];
                
        }
        rec(nextLevel, level + 1);
    }
};