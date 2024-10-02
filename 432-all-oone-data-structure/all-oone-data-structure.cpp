class AllOne {
public:
    struct Node {
        int val;
        Node* prev;
        Node* next;
        unordered_set<string> dict;

        Node() : val(0), prev(nullptr), next(nullptr) {};
        Node(int v) : val(v), prev(nullptr), next(nullptr) {};
        Node(int v, Node* p, Node* n) : val(v), prev(p), next(n) {};
    };
    Node* high;
    Node* low;
    unordered_map<string, Node*> ump;
    AllOne() {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        high = new Node(0);
        low = new Node(-1);
        high->next = low;
        low->prev = high;
    }
    
    void inc(string key) {
        if (ump.count(key)) {       // if key already exists or if cnt(key) >= 1
            Node* curr = ump[key];
            cout<<curr->val;
            if (curr->prev->val != curr->val + 1) { // if the node cnt(key)+1 dne create node
                Node* curr_prev = curr->prev;
                curr->prev = new Node(curr->val+1, curr_prev, curr);
                curr_prev->next = curr->prev;
            }
            curr->prev->dict.insert(key);   // insert into node cnt(key)+1
            ump[key] = curr->prev;
            curr->dict.erase(key);

            if (curr->dict.size() == 0) {
                // if curr(size) == 0 remove curr
                Node* curr_next = curr->next;
                curr->next->prev = curr->prev;
                curr->prev->next = curr->next;
                delete curr;
            }
        } else {
            // key dne in ump, new entry 
            if (low->prev->val != 1) {         // if node->val == 1 dne create node 1
                Node* low_prev = low->prev;
                low->prev = new Node(1, low_prev, low);
                low_prev->next = low->prev;
            }
            low->prev->dict.insert(key);
            ump[key] = low->prev;
        }
    }
    
    void dec(string key) {
        Node* curr = ump[key];  // as mentioned in q, cnt(key) >= 1 
        if (curr->val != 1) {
            // if cnt(key) > 1
            Node* curr = ump[key];
            // if node cnt(key)-1 dne
            if (curr->next->val != curr->val - 1) {
                Node* curr_next = curr->next;
                curr->next = new Node(curr->val-1, curr, curr_next);
                curr_next->prev = curr->next;
            }
            ump[key] = curr->next;
            ump[key]->dict.insert(key);
        }
        curr->dict.erase(key);
        if (curr->val == 1) ump.erase(key);     // if cnt(key) == 1, remove it from ump
        if (curr->dict.size() == 0) {       
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
        }
    }
    
    string getMaxKey() {
        if (high->next->val != -1) {
            return *high->next->dict.begin();
            return "";
        }
        return "";
    }
    
    string getMinKey() {
        if (low->prev->val != 0) {
            return *low->prev->dict.begin();
        }
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */