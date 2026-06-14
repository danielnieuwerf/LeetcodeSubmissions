/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    vector<int> vals;
public:
    vector<int> nextLargerNodes(ListNode* head) {
        auto curr = head;
        while(curr) {
            vals.push_back(curr->val);
            curr = curr->next;
        }
        int n = vals.size();
        vector<int> ans(n, 0);
        for(int i =0; i<n; ++i) {
            int j = i+1;
            while(j < n) {
                if(vals[j] > vals[i]) {
                    ans[i] = vals[j];
                    break;
                }
                ++j;
            }
        }
        return ans;
    }
};