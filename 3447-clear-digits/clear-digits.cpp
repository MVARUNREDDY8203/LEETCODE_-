class Solution {
public:
    string clearDigits(string s) {
        bool arr[101];
        queue<int> dig;
        for (int i=0; i<s.size(); i++) {
            arr[i] = 1;
            if (s[i] >= 'a' && s[i] <= 'z') continue;
            dig.push(i);
        }

        while (dig.size()) {
            int curr = dig.front();
            dig.pop();

            int prev = curr-1;
            while (!arr[prev]) prev--;
            arr[prev] = 0;
            arr[curr] = 0;
        }

        string ans = "";
        for (int i=0; i<s.size(); i++) if (arr[i]) ans += s[i];

        return ans;
    }
};