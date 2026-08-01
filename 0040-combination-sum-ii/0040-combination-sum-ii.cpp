class Solution {
public:
    void func(vector<int>& candidates, int start, int target,
              vector<int>& combin, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(combin);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;

            combin.push_back(candidates[i]);
            func(candidates, i + 1, target - candidates[i], combin, ans);
            combin.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> combin;
        func(candidates, 0, target, combin, ans);
        return ans;
    }
};