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
    int ans = 0;
public:
    int minimumOperations(TreeNode* root) {
        rec({root});
        return ans;
    }
    
    void rec(vector<TreeNode*> v) {
        if(v.empty()) return;
        vector<TreeNode*> nextLevel;
        vector<int> values;
        for(auto node: v) {
            if(node->left)
                nextLevel.push_back(node->left);
            if(node->right)
                nextLevel.push_back(node->right);
            values.push_back(node->val);
        }
        ans += getMinSwapsNeededForSorting(values);
        rec(nextLevel);
    }
    
    int getMinSwapsNeededForSorting(vector<int>& values) {
        int swaps = 0;
        int n = values.size();
        vector<int> target = values;
        sort(target.begin(), target.end());

        unordered_map<int, int> pos;
        for (int i = 0; i < n; ++i) {
            pos[values[i]] = i;
        }

        for (int i = 0; i < n; ++i) {
            if (values[i] != target[i]) {
                ++swaps;
                int curPos = pos[target[i]];
                pos[values[i]] = curPos;
                swap(values[curPos], values[i]);
            }
        }
        return swaps;
    }
};