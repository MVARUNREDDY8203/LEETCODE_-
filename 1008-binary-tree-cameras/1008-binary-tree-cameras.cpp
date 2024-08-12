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
    int util(TreeNode* root) {
        if (!root) return 0;

        int left_tree = util(root->left);
        int right_tree = util(root->right);

        if (left_tree == 'l' || right_tree == 'l') {
            root->val = 'c';
            return 'c';
        }
        if (left_tree == 'c' || right_tree == 'c') {
            root->val = 's';
            return 's';
        }
        root->val = 'l';
        return 'l';
    }
    int camera_counter(TreeNode* root) {
        if (!root) return 0;
        int cnt = 0;
        cnt += root->val == 'c' ? 1 : 0;
        cnt += camera_counter(root->left);
        cnt += camera_counter(root->right);
        return cnt;
    }
    int minCameraCover(TreeNode* root) {
        // if (!root->left && !root->right) return 1;
        util(root);
        if (root->val == 'l') root->val = 'c';
        return camera_counter(root);
    }
};