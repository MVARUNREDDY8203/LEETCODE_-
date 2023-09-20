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
    int k_global = 0;
    int ans;
    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);
        if(--k_global == 0){
            ans = root->val;
            return;
        }
        inorder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        k_global = k;
        inorder(root);
        return ans;
    }
};