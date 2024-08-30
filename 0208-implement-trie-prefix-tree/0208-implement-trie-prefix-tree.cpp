class TrieNode {
    public:
    TrieNode* children[26];
    bool isWord;
    TrieNode() {
        isWord = false;
        for (auto &child: children) child = nullptr;
    }
};
class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* p = root;
        for (int i=0; i<word.size(); i++) {
            int j = word[i] - 'a';
            if (p->children[j] == nullptr) p->children[j] = new TrieNode();
            p = p->children[j];
        }
        p->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* p = root;
        for (int i=0; i<word.size(); i++) {
            int j = word[i] - 'a';
            if (p->children[j] == nullptr) return false;
            p = p->children[j];
        }
        return p->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for (int i=0; i<prefix.size(); i++) {
            int j = prefix[i] - 'a';
            if (p->children[j] == nullptr) return false;
            p = p->children[j];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */