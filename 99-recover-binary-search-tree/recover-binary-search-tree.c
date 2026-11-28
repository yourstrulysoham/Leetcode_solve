/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * To find the imposter, we use an in-order traversal tracking the previous node and 
 * the current node. Since the in-order traversal traverses through the tree going from
 * the smallest node to the largest (sorted order). To find the rogue node, we need to catch
 * the last node that voilates the sorted order, in other words, the last node where the
 * previous node is larger than it would be our imposter.
 */
void findImposter(struct TreeNode* t, struct TreeNode** imposter, struct TreeNode** prev) {
    if(!t) return;

    findImposter(t->left, imposter, prev);
    
    // we make sure *prev is not NULL before derefrencing. 
    // Then if the previous node is larger than current,
    // current is out of place and therefore our imposter
    if (*prev && (*prev)->val > t->val) *imposter = t;
    *prev = t;
    
    findImposter(t->right, imposter, prev);
}

// Find imposters position and insert it there
void fixBST(struct TreeNode* t, struct TreeNode* imposter, bool *fixed) {
    if (!t) return;
    
    fixBST(t->left, imposter, fixed);
    if (*fixed) return;
    // Find the first node where imposters value is less
    // and swap the values.
    if (imposter->val < t->val) {
        int temp = imposter->val;
        imposter->val = t->val;
        t->val = temp; 
        *fixed = true;
        return;
    }
    
    fixBST(t->right, imposter, fixed);
}

void recoverTree(struct TreeNode* root) {
    struct TreeNode* imposter = NULL;
    struct TreeNode* prev = NULL;
    
    findImposter(root, &imposter, &prev);
    
    if (!imposter) return;
    bool fixed = false;
    fixBST(root, imposter, &fixed);
}