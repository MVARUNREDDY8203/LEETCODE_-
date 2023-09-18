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
    TreeNode* preorderer(TreeNode* root) {
        if (!root) return NULL;
        TreeNode* left_tree = preorderer(root->left);
        TreeNode* right_tree = preorderer(root->right);
        root->left = NULL;
        root->right = left_tree;
        TreeNode* curr = root;
        while (curr && curr->right) {
            curr = curr->right;
        }
        curr->right = right_tree;
        return root;
    }
    void flatten(TreeNode* root) {
        if (!root) return;
        root = preorderer(root);
    }
};
// void preorder(TreeNode* root, vector<TreeNode*> &arr) {
//     if (!root) return;
//     arr.push_back(root);
//     preorder(root->left, arr);
//     preorder(root->right, arr);
// }
// void flatten(TreeNode* root) {
//     if (!root) return;
//     vector<TreeNode*> arr;
//     preorder(root, arr);
//     arr.push_back(NULL);
//     for (int i=0; i<arr.size()-1; i++) {
//         arr[i]->right = arr[i+1];
//         arr[i]->left = NULL;
//     }
// }