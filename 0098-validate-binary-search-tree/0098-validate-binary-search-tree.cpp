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
    long long int prev = LONG_MIN;

    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        if (!isValidBST(root->left)) return false;
        if (root->val > prev) {
            prev = root->val;
            return isValidBST(root->right);
        }

        return false;
    }
};