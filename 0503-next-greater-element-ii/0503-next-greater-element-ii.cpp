class Solution {
public:
#define mini -1000000001
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> mono;
        vector<int> nge(n, mini);
        for (int i=n*n-1; i >= 0; i--) {
            if (nge[(i%n)] != mini) continue;

            if (!mono.empty()) {
                while (!mono.empty() && mono.top() <= nums[(i%n)]) mono.pop();
                if (!mono.empty()) nge[(i%n)] = mono.top();
            }
            
            mono.push(nums[(i%n)]);
        }
        for (int i=0; i<n; i++) {
            if (nge[i] == mini) nge[i] = -1;
        }
        return nge;
    }
};