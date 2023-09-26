class Solution {
public:
    string removeDuplicateLetters(string s) {
        if (s.size() == 1) return s;

        unordered_set<char> ust;
        unordered_map<char, int> ump;
        for (auto i: s) ump[i]++;

        stack<char> stk;
        for (int i=0; i<s.size(); i++) {
            if (ust.find(s[i]) == ust.end()) {
                while (!stk.empty() && ump[stk.top()] > 0 && stk.top() >= s[i]) {
                    ust.erase(stk.top());
                    stk.pop();
                } 
                stk.push(s[i]);
                ust.insert(s[i]);
            }
            ump[s[i]]--;
        }

        string ans = "";
        while (!stk.empty()) {
            ans = stk.top() + ans;
            stk.pop();
        }
        return ans;
    }
};