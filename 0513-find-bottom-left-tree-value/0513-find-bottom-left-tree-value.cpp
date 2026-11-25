class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = root->val;
        while(!q.empty()) {
            int size = q.size();
            ans = q.front()->val;
            for(int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left != NULL) {
                    q.push(temp->left);
                }
                if(temp->right != NULL) {
                    q.push(temp->right);
                }
            }
        }

        return ans;
    }
};