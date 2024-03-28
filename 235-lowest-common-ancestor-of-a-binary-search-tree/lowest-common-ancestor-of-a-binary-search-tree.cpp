/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (root->val > p->val && root->val > q->val) root = root->left;
            else if (root->val < p->val && root->val < q->val) root = root->right;
            else return root;
        }
        return NULL;
    }
};



// class Solution {
// public:
//     bool find(TreeNode* root, int p) {
//         if (!root) return false;

//         if (root->val == p) return true;
//         if (root->val < p) return find(root->right, p);
//         return find(root->left, p);
//     }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         int pp = p->val, qq = q->val;

//         queue<TreeNode*> que;
//         que.push(root);

//         TreeNode* ans = NULL;
//         // int deepest_lvl = 0;

//         while (!que.empty()) {
//             TreeNode* curr = que.front();
//             // int lvl = que.front().second;
//             que.pop();

//             if (find(curr, pp) && find(curr, qq)) {
//                 ans = curr;
//                 que.push(curr->left);
//                 que.push(curr->right);
//             }
//         }

//         return ans;
//     }
// };