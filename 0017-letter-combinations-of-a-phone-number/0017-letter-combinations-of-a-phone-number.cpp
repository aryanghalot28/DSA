class Solution {
public:
    unordered_map<char, string> f = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    void func(string &digits, int idx, string &diary, vector<string> &ans) {
        if (idx == digits.size()) {
            ans.push_back(diary);
            return;
        }
        string choice = f[digits[idx]];
        for (int j = 0; j < choice.size(); j++) {
            diary.push_back(choice[j]);
            func(digits, idx + 1, diary, ans);
            diary.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> ans;
        string diary = "";
        func(digits, 0, diary, ans);
        return ans;
    }
};