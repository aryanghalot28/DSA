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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)  return ans;

        vector<int> left=postorderTraversal(root->left);
        for(int x=0; x<left.size(); x++){
            ans.push_back(left[x]);
        }

        vector<int> right=postorderTraversal(root->right);
        for(int x=0; x<right.size(); x++){
            ans.push_back(right[x]);
        }
        
        ans.push_back(root->val);
        return ans;
    }
};