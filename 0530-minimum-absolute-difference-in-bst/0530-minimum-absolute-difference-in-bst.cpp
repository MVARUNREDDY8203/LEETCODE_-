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
    int min_val = INT_MAX;
    int prev = INT_MAX;
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        min_val = min(min_val, abs(prev - root->val));
        prev = root->val;
        inorder(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return min_val;
    }
};
// void preorder(TreeNode* root, vector<int> & vals) {
//     if (!root) return;
//     vals.push_back(root->val);
//     preorder(root->left, vals);
//     preorder(root->right, vals);
// }
// int getMinimumDifference(TreeNode* root) {
//     vector<int> vals;
//     preorder(root, vals);
//     int min_val = INT_MAX;
//     for(int i=0; i<vals.size(); i++){
//         for(int j=i+1; j<vals.size(); j++){
//             min_val = min(min_val, abs(vals[i]-vals[j]));
//         }
//     }
//     return min_val;
// }