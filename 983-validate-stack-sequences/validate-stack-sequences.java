class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer> stk = new Stack<>();
        int k = 0;
        for (var i : pushed) {
            stk.push(i);
            while (!stk.empty() && stk.peek() == popped[k]) {
                stk.pop();
                k++;
            }
        }
        return stk.isEmpty();
    }
}