class MagicDictionary {
public:
    MagicDictionary() {
        
    }
    vector<string> dict;
    void buildDict(vector<string> dictionary) {
        for (auto i: dictionary) dict.push_back(i);
    }
    
    bool search(string sw) {
        for (int i=0; i<dict.size(); i++) {
            if (dict[i].size() == sw.size()) {
                int diff = 0;
                for (int j=0; j<sw.size(); j++) {
                    if (diff > 1) break;
                    if (dict[i][j] != sw[j]) diff++;
                }
                cout<<diff<<endl;
                if (diff == 1) return true;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */