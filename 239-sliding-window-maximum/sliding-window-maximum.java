class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        List<Integer> ans = new ArrayList<>();
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        Map<Integer, Integer> ump = new HashMap<>();

        for (int i=0; i<k; i++) {
            pq.add(nums[i]);
            ump.put(nums[i], ump.getOrDefault(nums[i], 0) + 1);
        }
        ans.add(pq.peek());

        for (int i=k; i<nums.length; i++) {
            ump.put(nums[i-k], ump.getOrDefault(nums[i-k], 0) - 1);
            while (!pq.isEmpty() && ump.get(pq.peek()) <= 0) {
                pq.poll();
            }

            pq.add(nums[i]);
            ump.put(nums[i], ump.getOrDefault(nums[i], 0) + 1);

            ans.add(pq.peek());
        }

        int[] arr = new int[ans.size()];
        for (int i=0; i<ans.size(); i++) {
            arr[i] = ans.get(i);
        }

        return arr;
    }
}