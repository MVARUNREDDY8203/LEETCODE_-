class Solution {
public:
    bool util(stack<int> &stk, string &s, string &part) {
        stack<int> stk2 = stk;
        for (int k=part.size()-1; k>=0; k--) {
            if (s[stk2.top()] != part[k]) return false;
            stk2.pop();
        }
        return true;
    }
    string removeOccurrences(string s, string part) {
        stack<int> stk;
        int n = s.size(), m = part.size();
        for (int i=0; i<n; i++) {
            stk.push(i);
            if (stk.size() >= m && util(stk, s, part)) {
                for (int k=0; k<m; k++) {
                    s[stk.top()] = '0';
                    stk.pop();
                }
            }
        }

        cout<<s<<endl;
        string ans = "";
        for (int i=0; i<n; i++) if (s[i] != '0') ans += s[i];
        return ans;
    }
};