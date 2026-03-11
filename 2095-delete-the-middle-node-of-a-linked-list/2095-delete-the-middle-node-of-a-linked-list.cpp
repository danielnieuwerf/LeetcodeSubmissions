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
    ListNode* deleteMiddle(ListNode* head) {
        auto curr = head;
        int n = 0;
        while(curr) {
            ++n;
            curr = curr->next;
        }
        if (n == 1) {
            return nullptr;
        }
        curr = head;
        n /= 2;
        while(curr && n) {
            if(n != 1) {
                curr = curr->next;
                --n;
            } else {
                auto nodeToRemove = curr->next;
                curr->next = nodeToRemove->next;
                delete nodeToRemove;
                break;
            }
        }
        return head;
    }
};