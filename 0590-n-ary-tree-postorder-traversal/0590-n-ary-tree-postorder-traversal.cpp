/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    vector<int> _ans;
public:
    vector<int> postorder(Node* root) {
        rec(root);
        return _ans;
    }
    
    void rec(Node* root) {
        if(!root) return;
        for(auto& node: root->children)
            rec(node);
        _ans.push_back(root->val);
    }
};