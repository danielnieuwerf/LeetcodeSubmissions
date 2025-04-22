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
    vector<int> largestValues(TreeNode* root) {
        if(!root)
            return {};
        vector<TreeNode*> level { root };
        vector<int> ans;
        while(!level.empty()) {
            vector<TreeNode*> nextLevel; 
            int max_element = INT_MIN;
            for(auto node: level) {
                max_element = max(max_element, node->val);
                if(node->left)
                    nextLevel.push_back(node->left);
                if(node->right)
                    nextLevel.push_back(node->right);
            }
            ans.push_back(max_element);
            level = nextLevel;
        }
        return ans;
    }
};