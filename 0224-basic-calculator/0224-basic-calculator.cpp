class Solution {
public:
    int calculate(string s) {
        int num = 0;
        int ans = 0;
        int sign = 1;
        stack<int> signs;
        signs.push(1);

        for(auto c : s){
            if (c<='9' && c>='0') {
                num = num * 10 + (c - '0');
            } else if (c == '+' || c == '-') {
                ans = ans + signs.top() * sign * num;
                num = 0;
                sign = (c == '+' ? 1 : -1);
            } else if (c == '(') {
                signs.push(sign * signs.top());
                sign = 1;
            } else if (c == ')') {
                ans += signs.top() * sign * num;
                signs.pop();
                sign = 1;
                num = 0;
            }
        }

        if (num) {
            ans = ans + signs.top() * sign * num;
        }

        return ans;
    }
};