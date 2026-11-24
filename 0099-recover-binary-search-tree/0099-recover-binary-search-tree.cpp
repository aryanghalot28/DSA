
class Solution {
public:
    TreeNode* prev=NULL;
    TreeNode* first=NULL;
    TreeNode* mid=NULL;
    TreeNode* last=NULL;
    void inorder(TreeNode* root) {
        if(root == NULL) return;
        inorder(root->left);
        if(prev!=NULL && prev->val > root->val) {
            if(first==NULL) {
                first=prev;
                mid=root;
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
            swap(first->val,mid->val);
        }
    }
};

// class Solution {
// public:
//     TreeNode* prev=NULL;
//     TreeNode* first=NULL;
//     TreeNode* second=NULL;
//     void inorder(TreeNode* root){
//         if(root==NULL)  return;
//         inorder(root->left);
//         if(prev!=NULL && prev->val > root->val){
//             if(first==NULL){
//                 first=prev;
//             }
//             second=root;
//         }
//         prev=root;
//         inorder(root->right);
//     } 
//     void recoverTree(TreeNode* root) {
//         inorder(root);
//         swap(first->val, second->val);

        
        
//     }
// }; 