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
    long long int ans = LONG_MAX;
    long long int ans_copy = ans;
    void second_min(TreeNode* root, int min_val) {
        if (!root) return;
        if (root->val != min_val && root->val < ans) ans = root->val;
        second_min(root->left, min_val);
        second_min(root->right, min_val);
    }
    int findSecondMinimumValue(TreeNode* root) {
        second_min(root, root->val);
        if (ans == ans_copy) return -1;
        return ans;
    }
};