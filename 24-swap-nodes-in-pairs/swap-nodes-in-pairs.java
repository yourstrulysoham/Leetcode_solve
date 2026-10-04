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
    public ListNode swapPairs(ListNode head) { 
        
        if (head==null || head.next==null) return head;
        ListNode[] myNList=new ListNode[100];
        ListNode temp;
        ListNode current=head;
        //add nodes to array and count and flip while adding
        int i=0, j=0;
        while (current!=null){
            myNList[i]=current;
            if (i%2!=0){
                temp=myNList[i];
                myNList[i]=myNList[i-1];
                myNList[i-1]=temp;
            }
            i++;
            current=current.next;
        }
        //array ready with flipped nodes. now put the correct .next adresse
        for (j=0;j<i-1;j++){
            myNList[j].next=myNList[j+1];
        }

        myNList[i-1].next=null;
        
        return myNList[0];
    }
    
}