class Solution {
public:
    vector<string> ans;
    void solve(int open, int close, int n, string &c) {
        if(c.length() == 2 * n) {
            ans.push_back(c);
            return;
        }// for open braces
        if(open < n) {
            c.push_back('(');
            solve(open + 1, close, n, c);
            c.pop_back();
        }


        // for closeee braces
        if(close < open) {
            c.push_back(')');
            solve(open, close + 1, n, c);
            c.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string c = "";
        solve(0, 0, n, c);
        return ans;
    }
};