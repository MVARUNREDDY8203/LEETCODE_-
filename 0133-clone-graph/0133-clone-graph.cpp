/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        unordered_map<Node*, Node*> ump;
        queue<Node*> que;
        que.push(node);
        Node* curr;
        while (!que.empty()) {
            curr = que.front();
            if (!ump[curr]) {
                ump[curr] = new Node(curr->val);
            }
            for (auto i: curr->neighbors) {
                if (!ump[i]) {
                    ump[i] = new Node(i->val);
                    que.push(i);
                }
            }
            que.pop();
        }

        for (auto i: ump) {
            Node* keyn = i.first;
            Node* valn = i.second;
            
            for (auto j: keyn->neighbors) {
                valn->neighbors.push_back(ump[j]);
            }
        }

        return ump[node];
    }
};