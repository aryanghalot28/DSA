class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int prefix=0;
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            prefix+=nums[i];
            int rem=((prefix % k) + k)%k;
            ans+=mpp[rem];
            mpp[rem]++;
        }
        return ans;
    }

};