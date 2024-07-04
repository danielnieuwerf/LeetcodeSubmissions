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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans = nullptr;
        ListNode* current = nullptr;
        int sum = 0;
        ListNode* curr = head;
        while(curr)
        {
            sum += curr->val;
            if(sum != 0 && curr->val == 0)
            {
                if(!ans){
                    ans = new ListNode(sum);
                    current = ans;
                }
                else
                {
                    current->next = new ListNode(sum);
                    current = current->next;
                }
                
                sum = 0;
            }
            
            curr = curr->next;
        }
        
        return ans;
    }
};