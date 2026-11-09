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
    vector<TreeNode*> solve(int start, int end){
        if(start > end){
            return {NULL};
        }
        if(start == end){
            TreeNode* root = new TreeNode(start);
            return {root};
        }
        vector<TreeNode*> result;
        for(int x=start; x<=end; x++){
            vector<TreeNode*> left_bsts = solve(start, x-1);
            vector<TreeNode*> right_bsts = solve(x+1, end);

        for(int i = 0; i < left_bsts.size(); i++) {
            TreeNode* leftRoot = left_bsts[i];
            for(int j = 0; j < right_bsts.size(); j++) {
                TreeNode* rightRoot = right_bsts[j];
                TreeNode* root = new TreeNode(x);
                root->left = leftRoot;
                root->right = rightRoot;
                result.push_back(root);
            }
        }
    }
    return result;
}

    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
        
    }
};