class TrieNode {
    public:
    TrieNode* children[26];
    int cnt;
    bool isWord;
    TrieNode() {
        isWord = false;
        cnt = 0;
        for (int i=0; i<26; i++) children[i] = nullptr;
    }

    void insert(string &word) {
        TrieNode* node = this;
        for (int i=0; i<word.size(); i++) {
            int curr_node = word[i] - 'a';
            if (node->children[curr_node] == nullptr) node->children[curr_node] = new TrieNode(); 
            node = node->children[curr_node];
            node->cnt++;
        }
        node->isWord = true;
    }

    int prefixOfCnt(string &word) {
        TrieNode* node = this;
        int cnt = 0;
        for (int i=0; i<word.size(); i++) {
            int curr_node = word[i] - 'a';
            node = node->children[curr_node];
            cnt += node->cnt;
        }
        return cnt;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string &word: words) {
            root->insert(word);
        }
        vector<int> ans;
        for (string &word: words) {
            string sub = "";
            int cnt = root->prefixOfCnt(word);
            ans.push_back(cnt);
        }
        return ans;
    }
};