/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head==NULL || head->next==NULL)
        return head;
    struct ListNode* tmp = head;
    struct ListNode* curr = head->next;
    while(curr!=NULL) {
        if(tmp->val == curr->val) {
            curr=curr->next;
        }
        else {
            tmp->next = curr;
            tmp = curr;
            curr = tmp->next;
        }
    }
    tmp->next = NULL;
    return head; 
}