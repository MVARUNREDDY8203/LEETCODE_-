class Solution {
public:
    int min_depth = INT_MAX;
    void util (vector<int> &nums, int i) {
        if (i == 0) return;

        if (nums[i] < nums[i-1]) {
            cout<<nums[i]<<" "<<nums[i-1]<<endl;
            nums[i-1]--;
            min_depth = min(min_depth, i);
        }
        util (nums, i-1);
    }
    int monotoneIncreasingDigits(int n) {
        int num = n;

        vector<int> dig;
        while (num/10 > 0) {
            dig.push_back(num % 10);
            num = num/10;
        }
        dig.push_back(num % 10);

        if (dig.size() == 1) return n;

        reverse(dig.begin(), dig.end());

        util(dig, dig.size()-1);
        
        for (auto i: dig) cout<<i;
        cout<<endl<<min_depth;
        int ans = 0;
        for (int i=0; i<dig.size(); i++) {
            ans = ans * 10;
            ans += i >= min_depth ? 9 : dig[i];
        }
        return ans;
    }
};


// class Solution {
// public:
//     int monotoneIncreasingDigits(int n) {
//         for (int i=n; i>=0; i--) {
//             bool inc = true;
//             int num = i, prev = INT_MAX;

//             while (num / 10 > 0) {
//                 if (num % 10 <= prev) {
//                     prev = num % 10;
//                     num = num/10;
//                 }
//                 else {
//                     inc = false;
//                     break;
//                 }
//             }
//             if (num > prev) {
//                 inc = false;
//             }
//             if (inc) return i;
//         }
//         return 0;
//     }
// };