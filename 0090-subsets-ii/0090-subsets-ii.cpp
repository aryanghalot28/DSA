class Solution {
public:
    void func(vector<int>& nums, int ind, vector<int> &currentset, vector<vector<int>> &ans){
        ans.push_back(currentset);
        for(int i=ind; i<nums.size(); i++){
            if(i>ind && nums[i]==nums[i-1]){
                continue;
            }
            currentset.push_back(nums[i]);
            func(nums,i+1,currentset,ans);
            currentset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> currentset;
        vector<vector<int>> ans;
        func(nums,0,currentset,ans);
        return ans;
    }
};