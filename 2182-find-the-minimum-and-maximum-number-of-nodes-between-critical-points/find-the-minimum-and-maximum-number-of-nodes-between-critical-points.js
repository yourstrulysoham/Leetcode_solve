/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {number[]}
 */
var nodesBetweenCriticalPoints = function(head) {
    if (!head.next.next) return [-1, -1];

    let critPoints = [];
    let min = Number.MAX_SAFE_INTEGER;
    let cur = head.next;
    let index = 1; // start check at index 1
    while (cur.next) {
        if (head.val > cur.val && cur.val < cur.next.val || head.val < cur.val && cur.val > cur.next.val) {
            critPoints.push(index);

            if (critPoints.length > 1) {
                const diff = critPoints[critPoints.length-1] - critPoints[critPoints.length-2];
                min = (diff < min) ? diff : min;
            }
        }

        index++;
        head = cur;
        cur = cur.next;
    }

    if (critPoints.length < 2) return [-1, -1];

    const max = critPoints[critPoints.length-1] - critPoints[0];
    return [min, max];
};