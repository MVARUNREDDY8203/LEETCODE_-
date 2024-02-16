/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void corrector(TreeNode* root, vector<int> &vec, int &i) {
        if (!root) return;
        corrector(root->left, vec, i);
        root->val = vec[i++];
        corrector(root->right, vec, i);
    }
    void traversal_lnr(TreeNode* root, vector<int> &vec) {
        if (!root) return;
        traversal_lnr(root->left, vec);
        vec.push_back(root->val);
        traversal_lnr(root->right, vec);
    }
    void recoverTree(TreeNode* root) {
        vector<int> vec;
        traversal_lnr(root, vec);
        sort(vec.begin(), vec.end());
        int i=0;
        corrector(root, vec, i);
    }
};