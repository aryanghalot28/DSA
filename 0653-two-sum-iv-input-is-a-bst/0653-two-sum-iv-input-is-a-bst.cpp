
class Solution {
public:
    bool solve(TreeNode* root, int k, unordered_set<int>& mp) {
        if(root == NULL) return false;
        int remaining = k - root->val;
        if(mp.find(remaining) != mp.end())
            return true;
        mp.insert(root->val);
        return solve(root->left, k, mp) || 
               solve(root->right, k, mp);
    }

    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> mp;
        return solve(root, k, mp);
    }
};
