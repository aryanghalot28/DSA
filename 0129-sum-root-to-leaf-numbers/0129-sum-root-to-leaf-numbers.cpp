/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     int ans=0;
//     void func(TreeNode* root, int sum){
//         if(root==NULL)  return ;
//         sum=sum*10 + root->val;
//         if(root->left==NULL & root->right==NULL){
//             ans+=sum;
//             return;
//         }
//         func(root->left, sum);
//         func(root->right, sum);
//     }
//     int sumNumbers(TreeNode* root) {
//         ans=0;
//         func(root,0);
//         return ans;
        
//     }
// };
class Solution {
public:
    int func(TreeNode* root, int sum){
        if(root==NULL)  return 0;
        sum=sum*10 + root->val;
        if(root->left==NULL & root->right==NULL){
            return sum;
        }
        int left =func(root->left, sum);
        int right=func(root->right, sum);
        return left+right;
    }
    int sumNumbers(TreeNode* root) {
        return func(root,0);

        
    }
};