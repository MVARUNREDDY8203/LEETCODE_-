class Solution {
public:
    // int no_of_ones_in_binary(int n){
    //     if(n == 0) return 0;
    //     if(n == 1) return 1;
    //     return n%2 + no_of_ones_in_binary(n/2);
    // }
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        if(n == 0) return ans;
        ans[1] = 1;
        if(n == 1) return ans;
        
        for(int i=2; i<=n; i++){
            ans[i] = ans[i/2] + i%2;
        }
        return ans;
    }
};