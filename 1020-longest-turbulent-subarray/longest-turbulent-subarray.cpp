class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if (arr.size() == 1) return 1;
        if (arr.size() == 2) {
            if (arr[0] != arr[1]) return 2;
            return 1;
        } 
        bool lt = !(arr[1] < arr[0]);
        int ans = 0, sub_ans = 2;
        for (int i=2; i<arr.size(); i++) {
            if (lt && arr[i] < arr[i-1]) {
                sub_ans++;
                lt = !lt;
            }
            else if (!lt && arr[i] > arr[i-1]) {
                sub_ans++;
                lt = !lt;
            }
            else {
                if (arr[i] == arr[i-1]) {
                    sub_ans = 1;
                    continue;
                }
                sub_ans = 2;
                lt = !(arr[i] < arr[i-1]);
            }
            ans = max(ans, sub_ans);
            cout<<i<<" "<<lt<<" "<<sub_ans<<" "<<ans<<endl;
        }
        ans = max(ans, sub_ans);
        return ans;
    }
};