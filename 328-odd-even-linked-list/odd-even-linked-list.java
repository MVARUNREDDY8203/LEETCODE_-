/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode oddEvenList(ListNode head) {
        ListNode odd = new ListNode(0);
        ListNode even = new ListNode(0);
        ListNode oddptr = odd;
        ListNode evenptr = even;

        ListNode curr = head;
        int idx = 1;
        while (curr != null) {
            if (idx % 2 == 1) {
                oddptr.next = curr;
                oddptr = oddptr.next;
            }
            else {
                evenptr.next = curr;
                evenptr = evenptr.next;
            }
            curr = curr.next;
            idx++;
        }
        evenptr.next = null;
        oddptr.next = even.next;
        return odd.next;
    }
}