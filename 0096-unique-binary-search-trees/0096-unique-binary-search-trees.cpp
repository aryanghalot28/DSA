
class Solution {
public:
    int solve(int start, int end, vector<vector<int>>& dp) {
        if(start > end) {
            return 1;
        }
        if(dp[start][end] != -1) {
            return dp[start][end];
        }
        int ans = 0;
        for(int x = start; x <= end; x++) {
            int left = solve(start, x-1, dp);
            int right = solve(x+1, end, dp);
            ans = ans + (left * right);
        }
        return dp[start][end] = ans;
    }
    int numTrees(int n) {
        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
        return solve(1, n, dp);
    }
};
