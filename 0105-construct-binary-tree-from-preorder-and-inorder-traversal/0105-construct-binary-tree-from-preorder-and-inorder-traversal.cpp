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
class Solution {
public:
    TreeNode* construct(vector<int>& preorder, int left, int right, int& preIndex, unordered_map<int,int>& mpp){
        if(left>right)  return NULL;
        int rootval = preorder[preIndex];
        preIndex++;
        TreeNode* root=new TreeNode(rootval);
        int pos=mpp[rootval];
        root->left=construct(preorder,left,pos-1,preIndex,mpp);
        root->right=construct(preorder,pos+1,right,preIndex,mpp);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mpp;
        for(int i=0; i<inorder.size(); i++){
            mpp[inorder[i]]=i;
        }
        int preIndex=0;
        return construct(preorder,0,inorder.size()-1,preIndex,mpp);
        
    }

};