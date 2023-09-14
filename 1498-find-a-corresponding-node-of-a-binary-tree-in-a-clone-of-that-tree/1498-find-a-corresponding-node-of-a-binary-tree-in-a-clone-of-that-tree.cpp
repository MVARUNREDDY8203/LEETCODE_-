/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* preorder(TreeNode* root, int target) {
        if (!root) return NULL;
        if (root->val == target) return root;
        TreeNode* curr = preorder(root->left, target);
        if (curr) return curr;
        curr = preorder(root->right, target);
        if (curr) return curr;
        return NULL;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        int val = target->val;
        return preorder(cloned, val);
    }
};