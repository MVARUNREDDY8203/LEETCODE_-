class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        struct cmp {
            bool operator()(const pair<int, int> &a, const pair<int, int>&b) {
                return  (double)(a.first + 1)/(double)(a.second + 1) - (double)(a.first)/(double)(a.second)
                < (double)(b.first + 1)/(double)(b.second + 1) - (double)(b.first)/(double)(b.second);
            }  
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for (vector<vector<int>>::iterator it = classes.begin(); it != classes.end(); ++it) {
            pq.push({(*it)[0], (*it)[1]});
        }

        while (extraStudents > 0) {
            pair<int, int> temp= pq.top();
            pq.pop();

            temp.first = temp.first + 1;
            temp.second = temp.second + 1;

            pq.push(temp);
            extraStudents--;
        }

        double ans = 0;
        while (!pq.empty()) {
            ans += (double)pq.top().first / (double)pq.top().second;
            pq.pop();
        }
        ans /= classes.size();
        return ans;
    }
};