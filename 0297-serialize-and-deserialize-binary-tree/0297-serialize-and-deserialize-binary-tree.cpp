/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "null";
        queue<TreeNode*> que;
        que.push(root);
        string ans = "";
        while (!que.empty()) {
            TreeNode* curr = que.front();
            que.pop();
            if (curr == nullptr) {
                ans += "null,";
            }
            else {
                ans += to_string(curr->val) + ",";
                que.push(curr->left);
                que.push(curr->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string item;
        stringstream ss(data);
        vector<string> values;
        while (getline(ss, item, ',')) {
            values.push_back(item);
        }

        if (values[0] == "null") return nullptr;
        TreeNode* root = new TreeNode(stoi(values[0]));
        queue<TreeNode*> que;
        que.push(root);
        int i=1;
        while (!que.empty()) {
            TreeNode* curr = que.front();
            que.pop();

            string left_val = values[i++];
            if (left_val != "null") {
                curr->left = new TreeNode(stoi(left_val));
                que.push(curr->left);
            } 
            string right_val = values[i++];
            if (right_val != "null") {
                curr->right = new TreeNode(stoi(right_val));
                que.push(curr->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));