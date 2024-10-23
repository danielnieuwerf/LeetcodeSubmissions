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
    vector<long long> levels;
    
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        rec({root});
        sort(levels.begin(), levels.end());
        if(levels.size() < k)
            return -1;
        return *(levels.end() - k);
    }
    
    void rec(vector<TreeNode*> level) {
        if(level.empty()) return;
        
        long long sum = 0;
        vector<TreeNode*> nextLevel;
        for(auto node: level)
            if(node) {
                sum += (long long) node->val;
                if(node->left)
                    nextLevel.push_back(node->left);
                if(node->right)
                    nextLevel.push_back(node->right);
            }
        levels.push_back(sum);
        return rec(nextLevel);
    }
};