class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size(); 
        int sum=0;
        int index=0;
        vector<int>diary;
        vector<vector<int>> ans;
        func(candidates, n, index, diary, sum, ans, target);
        return ans; 
    }
    void func(vector<int>& candidates, int n, int index, vector<int> &diary, int sum, vector<vector<int>> &ans, int target){

        if(index==n){
            if(sum==target){
                ans.push_back(diary);
            }
            return;
        }

        //nhi lena
        func(candidates, n, index+1, diary, sum, ans, target);

        //agr lenge to
        if(sum + candidates[index] <= target){
            diary.push_back(candidates[index]);
            sum+=candidates[index];
            func(candidates, n, index, diary, sum, ans, target);
            diary.pop_back();
            sum-=candidates[index];
        }
        return;
    }
};