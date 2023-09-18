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
    int ans = 0;
    void Traversal(TreeNode* root, int val) {
        if (!root) return;
        if (!root->left && !root->right) {
            ans += val*10 + root->val;
            cout<<val*10 + root->val<<endl;
        } 
        Traversal(root->left, val*10 + root->val);
        Traversal(root->right, val*10 + root->val);
    }
    int sumNumbers(TreeNode* root) {
        Traversal(root, 0);
        return ans;
    }
};