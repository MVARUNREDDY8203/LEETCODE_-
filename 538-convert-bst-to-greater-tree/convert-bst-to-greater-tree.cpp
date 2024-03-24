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
    int util(TreeNode* root, int parent_right_sum) {
        if (!root) return 0;

        int right = util(root->right, parent_right_sum);

        int root_val = root->val;
        root->val = root_val + right + parent_right_sum;
        
        int left = util(root->left, root->val);

        int subtree_sum = left + root_val + right;
        return subtree_sum;
    }
    TreeNode* convertBST(TreeNode* root) {
        util(root, 0);
        return root;
    }
};