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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};

        queue<TreeNode*> que;
        vector<int> ans;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            ans.push_back(que.back()->val);
            for (int i=0; i<size; i++) {
                if (que.front()->left) que.push(que.front()->left);
                if (que.front()->right) que.push(que.front()->right);
                que.pop();
            }
        }
        return ans;
    }
};
// vector<int> rightSideView(TreeNode* root) {
//     if (!root) return {};

//     vector<vector<TreeNode*>> lvls;
//     lvls.push_back({root});
//     int i = 0;
//     while (true) {
//         vector<TreeNode*> temp;
//         for (int j=0; j<lvls[i].size(); j++) {
//             if(lvls[i][j]->left) temp.push_back(lvls[i][j]->left);
//             if(lvls[i][j]->right) temp.push_back(lvls[i][j]->right);
//         }
//         if(temp.size() == 0) break;
//         lvls.push_back(temp);
//         i++;
//     }

//     vector<int> ans;
//     for (auto i: lvls) {
//         ans.push_back(i.back()->val);
//     }
    
//     return ans;
// }