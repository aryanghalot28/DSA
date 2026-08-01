class Solution {
public:

    set<vector<int>> s; // to remove duplicate combinations in ans
    void func(vector<int>& candidates, int i, int target, vector<vector<int>> &ans, vector<int> &combin){

        //base cases
        if(target==0){
            if(s.find(combin)==s.end()){
                ans.push_back(combin);
                s.insert(combin);                
            }
            return;
        }

        if(i==candidates.size() || target < 0){
            return;
        }
        combin.push_back(candidates[i]);
        //single inclusion(1 baar element lena hai)..means call func for i+1 and target-candidates[i]
        func(candidates, i+1, target-candidates[i], ans, combin);

        //multiple times inclusion(baar baar lena mtlb i same rhega)
        func(candidates, i, target-candidates[i], ans, combin);

        //lena hi nhi hai...just do i+1....but usse pehle backtrack krke element remove krna hoga combin se
        combin.pop_back();
        //now call func
        func(candidates, i+1, target, ans, combin);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>combin;

        func(candidates,0,target,ans,combin);
        return ans;
        
    }
};