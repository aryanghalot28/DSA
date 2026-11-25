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
//     int countNodes(TreeNode* root) {
//         if(root==NULL) return 0;
//         int left=countNodes(root->left);
//         int right=countNodes(root->right);
//         return 1+left+right;
        
//     }
// };

class Solution {
public:
    int countNodes(TreeNode* root){
        if(root==NULL)  return 0;
        //this code is used to calculate left height of the tree
        int left = 0;
        TreeNode* temp = root;
        while(temp!=NULL){
            left++;
            temp=temp->left;
        }
        //this code is used to calculate the right height of the tree
        int right=0;
        TreeNode* temp1 = root;
        while(temp1!=NULL){
            right++;
            temp1=temp1->right;
        }
        if(left==right) return pow(2, left)-1; // or pow(2, right)-1   
        else{
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};