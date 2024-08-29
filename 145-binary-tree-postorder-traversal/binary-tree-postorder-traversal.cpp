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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> traversal;
        vector<int> preorder;
        TreeNode* curr = root;
        while (curr || !traversal.empty()) {
            if (curr != nullptr) {
                preorder.push_back(curr->val);
                traversal.push(curr);
                curr = curr->right;
            }
            else {
                curr = traversal.top();
                traversal.pop();
                curr = curr->left;
            }
        }
        reverse(preorder.begin(), preorder.end());
        return preorder;
    }
};