class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        stack<int> zeros, l1, r1;
        for (int i=0; i<n; i++) {
            if (locked[i] == '0') zeros.push(i);
            if (locked[i] == '1') {
                if (s[i] == '(') l1.push(i);
                if (s[i] == ')') {
                    if (l1.size()) {
                        int j = l1.top();
                        l1.pop();

                        locked[i] = '2';
                        locked[j] = '2';
                        continue;
                    }
                    if (zeros.size()) {
                        int j = zeros.top();
                        zeros.pop();

                        locked[i] = '2';
                        locked[j] = '2';
                        continue;
                    }
                    return false;
                }
            }
        }
        
        int zs = 0;
        for (int i=n-1; i>=0; i--) {
            if (locked[i] == '0') zs++;
            if (locked[i] == '1') {
                if (zs > 0) {
                    zs--;
                    continue;
                }
                return false;
            }
        }
        
        return (zs % 2 == 0);
    }
};