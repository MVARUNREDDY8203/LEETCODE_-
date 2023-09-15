/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    int height_finder(Node* root) {
        if (!root) return 0;
        int left = height_finder(root->left);
        int right = height_finder(root->right);
        return 1 + max(left, right);
    }
    Node* connect(Node* root) {
        int h = height_finder(root);

        vector<vector<Node*>> level;

        level.push_back({root});
        for (int i=0; i<h-1; i++) {
            vector<Node*> temp;
            for (int j=0; j<level[i].size(); j++) {
                if (level[i][j]->left) temp.push_back(level[i][j]->left);
                if (level[i][j]->right) temp.push_back(level[i][j]->right);
            }     
            level.push_back(temp);
        }

        for (int i=0; i<h; i++) {
            for (int j=0; j<level[i].size()-1; j++) {
                level[i][j]->next = level[i][j+1];
            }
        }

        return root;
    }
};