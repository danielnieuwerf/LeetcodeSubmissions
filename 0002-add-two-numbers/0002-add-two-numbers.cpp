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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* ans = l1 || l2 ? new ListNode(0) : nullptr;
        auto curr = ans;
        int i = 0;
        while(l1 || l2) {
            int total = carry;
            if(l1) {
                total += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                total += l2->val;
                l2 = l2->next;
            }
            carry = total >= 10 ? 1 : 0;
            curr->val = total%10;
            if(l1 || l2 || carry) {
                auto nextNode = new ListNode(0);
                curr->next = nextNode;
                curr = nextNode;
            }
        }
        if(carry)
            curr->val = carry;
        return ans;
    }
};