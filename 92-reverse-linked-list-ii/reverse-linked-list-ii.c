/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode *h = head, *s = h, *c, *p = NULL, *n, *t;
    int i = 1;
    for (; h && i < left ; p = h, h = h->next, i++);
    for (c = p, t = h ; i <= right ; n = h->next, h->next = p, p = h, h = n, i++);
    return c && (c->next = p), t && (t->next = h), t == s ? p : s;
}