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
    TreeNode* util_low(TreeNode* root, int low) {
        if (!root) return NULL;
        if (root->val > low) {
            root->left = util_low(root->left, low);
            return root;
        }
        else if (root->val < low) return util_low (root->right, low);
        
        root->left = NULL;
        return root;
    }
    TreeNode* util_high(TreeNode* root, int high) {
        if (!root) return NULL;
        if (root->val < high) {
            root->right = util_high(root->right, high);
            return root;
        }
        else if (root->val > high) return util_high(root->left, high);
        
        root->right = NULL;
        return root;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* root2 = util_low(root, low);
        return util_high(root2, high);
    }
};