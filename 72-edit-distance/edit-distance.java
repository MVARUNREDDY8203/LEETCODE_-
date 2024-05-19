class Solution {
    public int util (int i, int j, String word1, String word2, int dp[][]) {
        // base case
        if (j >= word2.length()) {
            if (i >= word1.length()) {
                return 0;
            }
            return word1.length() - i;
        }
        if (i >= word1.length() && j < word2.length()) return word2.length() - j;

        if (dp[i][j] != -1) {
            return dp[i][j];
        }


        if (word1.charAt(i) == word2.charAt(j)) return util(i+1, j+1, word1, word2, dp);
        int ans = Integer.MAX_VALUE;
        // insert a char in word1
        ans = Math.min(ans, util(i, j+1, word1, word2, dp));
        // replace a char in word1
        ans = Math.min(ans, util(i+1, j+1, word1, word2, dp));
        // delete a char in word1
        ans = Math.min(ans, util(i+1, j, word1, word2, dp));

        return  dp[i][j] = 1 + ans;
    }
    public int minDistance(String word1, String word2) {
        int dp[][] = new int[502][502];
        for (int i=0; i<502; i++) {
            for (int j=0; j<502; j++) dp[i][j] = -1;
        }
        return util (0, 0, word1, word2, dp);
    }
}