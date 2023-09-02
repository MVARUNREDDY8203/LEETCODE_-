class Solution {
public:
    int no_of_ones_in_binary(int n){
        if(n == 0) return 0;
        if(n == 1) return 1;
        return n%2 + no_of_ones_in_binary(n/2);
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        for(int i=0; i<=n; i++){
            ans[i] = no_of_ones_in_binary(i);
        }
        return ans;
    }
};