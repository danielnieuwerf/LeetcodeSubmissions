/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        auto curr = head;
        vector<Node*> list;
        vector<Node*> randoms;
        int n = 0;
        while(curr) {
            randoms.push_back(curr->random);
            list.push_back(curr);
            ++n;
            curr = curr->next;
        }
        if(list.empty())
            return nullptr;

        vector<Node*> newList;
        newList.reserve(n);
        Node* ans = new Node(list[0]->val);
        newList.push_back(ans);
        curr = ans;
        for(int i = 1; i<n; ++i) {
            curr->next = new Node(list[i]->val);
            newList.push_back(curr->next);
            curr = curr->next;
        }
        curr = ans;
        for(int i = 0; i<n; ++i) {
            int j = 0;
            for(j = 0; j<n; ++j) { // o(n^2) time can be improved using hash map.
                if(list[j] == randoms[i]) {
                    break;
                }
            }
            curr->random = j == n ? nullptr : newList[j];
            curr = curr->next;
        }
        return ans;
    }
};