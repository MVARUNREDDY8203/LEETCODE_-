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
    int preorder_index = 0;
    unordered_map<int, int> inorder_index_of;

    TreeNode* array_to_tree(vector<int> &preorder, int left, int right) {
        if (left > right) return NULL;

        TreeNode* root = new TreeNode(preorder[preorder_index++]);

        root->left = array_to_tree(preorder, left, inorder_index_of[root->val]-1);
        root->right = array_to_tree(preorder, inorder_index_of[root->val]+1, right);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i=0; i<inorder.size(); i++) {
            inorder_index_of[inorder[i]] = i;
        }

        return array_to_tree(preorder, 0, inorder.size()-1);
    }
};