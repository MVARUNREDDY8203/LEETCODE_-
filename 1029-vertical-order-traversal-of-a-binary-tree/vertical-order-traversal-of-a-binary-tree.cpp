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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>>> que;     // <col, row>
        map<int, map<int, vector<int>>> ump;  //col -> row 
        set<int> cols;

        que.push({root, {0, 0}});
        while (!que.empty()) {
            TreeNode* curr = que.front().first;
            int col = que.front().second.first;
            int row = que.front().second.second;
            que.pop();
            if (!curr) continue;

            cols.insert(col);

            ump[col][row].push_back(curr->val);
            que.push({curr->left, {col-1, row+1}});
            que.push({curr->right, {col+1, row+1}});
        }

        vector<vector<int>> ans;
        for (auto col: cols) {
            // cout<<"col: "<<col<<endl;
            vector<int> temp;
            for (auto row: ump[col]) {
                // cout<<"row "<<row.first<<endl;
                sort(ump[col][row.first].begin(), ump[col][row.first].end());
                for (auto item: ump[col][row.first]) {
                    // cout<<item<<" ";
                    temp.push_back(item); 
                }
                // cout<<endl; // ump[col][row] is a set, every item in the set // max possible items in every ump[col][row] is 2
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         queue<pair<TreeNode*, int>> que;
//         unordered_map<int, vector<int>> ump;

//         set<int> idxes;
//         que.push({root, 0});
//         while (!que.empty()) {
//             TreeNode* curr = que.front().first;
//             int idx = que.front().second;
//             que.pop();
//             if (!curr) continue;

//             idxes.insert(idx);

//             ump[idx].push_back(curr->val);
//             que.push({curr->left, idx-1});
//             que.push({curr->right, idx+1});
//         }

//         vector<vector<int>> ans;

//         for (auto i: idxes) {
//             sort(ump[i].begin(), ump[i].end());
//             ans.push_back(ump[i]);
//         }
//         return ans;
//     }
// };