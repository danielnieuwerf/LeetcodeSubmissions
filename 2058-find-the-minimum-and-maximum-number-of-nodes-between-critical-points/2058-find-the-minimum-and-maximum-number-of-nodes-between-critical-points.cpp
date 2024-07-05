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
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;
        auto curr = head->next;
        auto prev = head;
        int i = 1;
        while(curr) {
            if(!curr->next) break;
            if(curr-> val > prev->val && curr->val > curr->next->val) {
                ans.push_back(i);
            } else if(curr-> val < prev->val && curr->val < curr->next->val) {
                ans.push_back(i);
            }
            
            ++i;
            curr = curr->next;
            prev = prev->next;
        }
        int n = ans.size();
        if(n<2) return {-1, -1};
        sort(ans.begin(),ans.end());
        int minDistance = 1e5;
        int maxDistance = ans.back() - ans[0];
        for(int i = 1; i<n; ++i)
            minDistance = min(minDistance, ans[i]-ans[i-1]);
        return {minDistance, maxDistance};
    }
};