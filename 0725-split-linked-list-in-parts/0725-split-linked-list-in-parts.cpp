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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        auto n = 0;
        auto curr = head;
        while(curr) {
            ++n;
            curr = curr->next;
        }
        
        int len = n/k;
        int extra = n%k;
        if(n<k) {
            extra = 0;
            len = 1;
        }
        
        int next = 0;
        vector<ListNode*> ans;
        curr = head;
        for(int i = 0; i<n; ++i) {
            if(next == 0) {
                ans.push_back(curr);
                next = len;
                if(extra > 0) {
                    --extra;
                    ++next;
                }
            }
            --next;
            auto temp = curr->next;
            if(next == 0) {
                curr->next = nullptr;
            }
            curr = temp;
        }
        
        while(n<k) {
            ans.push_back({});
            ++n;
        }
        
        return ans;
    }
};