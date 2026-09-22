
#include <stdlib.h>

typedef struct {
    int product;       // Product of the whole segment % k
    int count[5];      // count[r] = number of prefix products having remainder r
} Node;

int K;

/* Merge two segment tree nodes */
Node merge(Node left, Node right) {
    Node res;

    // Product of complete segment
    res.product = (left.product * right.product) % K;

    // Start with prefixes completely inside left
    for (int r = 0; r < K; r++) {
        res.count[r] = left.count[r];
    }

    // Prefixes that take all of left + prefix of right
    for (int r = 0; r < K; r++) {
        int newRemainder = (left.product * r) % K;
        res.count[newRemainder] += right.count[r];
    }

    return res;
}

/* Build segment tree */
void build(Node *tree, int *nums, int node, int start, int end) {
    if (start == end) {
        int rem = nums[start] % K;

        tree[node].product = rem;

        for (int r = 0; r < K; r++) {
            tree[node].count[r] = 0;
        }

        // Single element is one possible prefix
        tree[node].count[rem] = 1;

        return;
    }

    int mid = (start + end) / 2;

    build(tree, nums, node * 2, start, mid);
    build(tree, nums, node * 2 + 1, mid + 1, end);

    tree[node] = merge(tree[node * 2],
                        tree[node * 2 + 1]);
}

/* Point update */
void update(Node *tree, int node, int start, int end,
            int index, int value) {

    if (start == end) {
        int rem = value % K;

        tree[node].product = rem;

        for (int r = 0; r < K; r++) {
            tree[node].count[r] = 0;
        }

        tree[node].count[rem] = 1;

        return;
    }

    int mid = (start + end) / 2;

    if (index <= mid) {
        update(tree, node * 2, start, mid, index, value);
    } else {
        update(tree, node * 2 + 1, mid + 1, end, index, value);
    }

    tree[node] = merge(tree[node * 2],
                        tree[node * 2 + 1]);
}

/* Query a range */
Node query(Node *tree, int node, int start, int end,
           int left, int right) {

    // Completely inside range
    if (left <= start && end <= right) {
        return tree[node];
    }

    int mid = (start + end) / 2;

    // Entirely in right side
    if (left > mid) {
        return query(tree, node * 2 + 1,
                     mid + 1, end, left, right);
    }

    // Entirely in left side
    if (right <= mid) {
        return query(tree, node * 2,
                     start, mid, left, right);
    }

    // Range crosses both sides
    Node L = query(tree, node * 2,
                   start, mid, left, right);

    Node R = query(tree, node * 2 + 1,
                   mid + 1, end, left, right);

    return merge(L, R);
}

/**
 * Note: The returned array must be malloced,
 * assume caller calls free().
 */
int* resultArray(int* nums, int numsSize, int k,
                 int** queries, int queriesSize,
                 int* queriesColSize, int* returnSize) {

    K = k;

    // Segment tree
    Node *tree = (Node *)calloc(4 * numsSize, sizeof(Node));

    build(tree, nums, 1, 0, numsSize - 1);

    // Result array
    int *result = (int *)malloc(queriesSize * sizeof(int));

    for (int q = 0; q < queriesSize; q++) {

        int index = queries[q][0];
        int value = queries[q][1];
        int start = queries[q][2];
        int x = queries[q][3];

        // Update nums[index] permanently
        nums[index] = value;

        update(tree, 1, 0, numsSize - 1,
               index, value);

        // Get all prefix products from start to end
        Node ans = query(tree, 1, 0, numsSize - 1,
                         start, numsSize - 1);

        result[q] = ans.count[x];
    }

    *returnSize = queriesSize;

    free(tree);

    return result;
}