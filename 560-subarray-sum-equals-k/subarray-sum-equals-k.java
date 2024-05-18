class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer> ump = new HashMap<>();
        int sum = 0;
        int ans = 0;
        // Map.add(0);
        for (int i=0; i<nums.length; i++) {
            sum += nums[i];
            if (sum == k) ans++;
            ans += ump.getOrDefault(sum - k, 0);
            ump.put(sum, ump.getOrDefault(sum, 0) + 1);
        }
        return ans;
    }
}