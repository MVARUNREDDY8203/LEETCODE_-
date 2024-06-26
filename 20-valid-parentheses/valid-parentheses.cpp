class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<int> stk;
        for (int i=0; i<n; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') stk.push(s[i]);
            if (s[i] == ')') {
                if (!stk.empty() && stk.top() == '(') {
                    stk.pop();
                    continue;
                }
                return false;
            }
            if (s[i] == '}') {
                if (!stk.empty() && stk.top() == '{') {
                    stk.pop();
                    continue;
                }
                return false;
            }
            if (s[i] == ']') {
                if (!stk.empty() && stk.top() == '[') {
                    stk.pop();
                    continue;
                }
                return false;
            }
        }
        return stk.size() == 0;
    }
};