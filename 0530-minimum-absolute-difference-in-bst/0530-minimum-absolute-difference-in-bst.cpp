class Solution {
public:
    TreeNode* prev = NULL;
    int ans = INT_MAX;

    void inorder(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        inorder(root->left);

        if (prev != NULL) {
            int diff = root->val - prev->val;
            ans = min(ans, diff);
        }

        prev = root;

        inorder(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return ans;
    }
};