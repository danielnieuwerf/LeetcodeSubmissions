/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        string s;

        while(head!=NULL){
            s += to_string(head->val);
            head = head->next;
        }

        int ans = 0;
        int len = s.size();
        
        for(int i=0; i<len; ++i) {
            if(s[i]=='1') {
                ans += pow(2,len-i-1);
            }
        }
        
        return ans;
    }
};