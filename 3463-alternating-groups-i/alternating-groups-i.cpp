class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        colors.push_back(colors[0]);
        colors.push_back(colors[1]);
        int cnt = 0;
        for (int i=1; i<=colors.size()-2; i++) {
            if (colors[i-1] == colors[i+1] && colors[i-1] != colors[i]) cnt++;
        }
        return cnt;
    }
};