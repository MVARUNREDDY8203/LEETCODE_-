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
    unordered_map<int, int> index_of_inorder;
    int inv_preorder_index = 0;
    TreeNode* buildTree_util(vector<int> &inv_preorder, int left, int right) {
        if (left > right) return NULL;

        TreeNode* root = new TreeNode(inv_preorder[inv_preorder_index++]);

        root->right = buildTree_util(inv_preorder, index_of_inorder[root->val]+1, right);
        root->left = buildTree_util(inv_preorder, left, index_of_inorder[root->val]-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        reverse(postorder.begin(), postorder.end());

        for (int i=0; i<inorder.size(); i++) {
            index_of_inorder[inorder[i]] = i;
        }

        return buildTree_util(postorder, 0, postorder.size()-1);
    }
};