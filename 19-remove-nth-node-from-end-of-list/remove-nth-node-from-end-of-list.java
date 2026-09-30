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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int s=size(head);
        if(s==1){
            return null;
        }
        ListNode prev = get(s - n - 1,head);

        if (prev != null) {
            prev.next = prev.next.next;
            return head;
        }
        head=head.next;
        return head;
            
    }
    public ListNode get(int index,ListNode h) {
       if(index>-1) {
            ListNode node = h;
            for (int i = 0; i < index; i++) {
                node = node.next;
            }
            return node;
        }
        else{
            return null;
        }
    }
    public int size(ListNode h){
        ListNode node = h;
        int size = 0;
        while(node != null){
            size++;
            node = node.next;
        }
        return size;
    }
}