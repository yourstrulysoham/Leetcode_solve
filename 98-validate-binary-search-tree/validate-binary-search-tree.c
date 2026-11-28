/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool est_bon(struct TreeNode* root, struct TreeNode* min, struct TreeNode* max) {
    if (root == NULL)
        return true;
    if (min == NULL && max == NULL)
        return est_bon (root->left, min, root) && est_bon(root->right, root, max);
    if (min == NULL) 
        return root-> val < max->val && est_bon (root->left, min, root) && est_bon(root->right, root, max);
    if (max == NULL) 
        return root-> val > min->val && est_bon (root->left, min, root) && est_bon(root->right, root, max);
    return (root->val < max->val && root -> val > min->val && est_bon (root->left, min, root) && est_bon(root->right, root, max));
}

bool isValidBST(struct TreeNode* root) {
    return est_bon(root, NULL, NULL);
}