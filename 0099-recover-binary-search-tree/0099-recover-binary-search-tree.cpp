
class Solution {
public:
    TreeNode* prev=NULL;
    TreeNode* first=NULL;
    TreeNode* middle=NULL;
    TreeNode* last=NULL;
    void inorder(TreeNode* root) {
        if(root == NULL) return;
        inorder(root->left);
        if(prev!=NULL && prev->val > root->val) {
            if(first==NULL) {
                first=prev;
                middle=root;
            }
            else {
                last =root;
            }
        }
        prev = root;
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        if(last != NULL) {
            swap(first->val, last->val);
        }
        else {
            swap(first->val, middle->val);
        }
    }
};
