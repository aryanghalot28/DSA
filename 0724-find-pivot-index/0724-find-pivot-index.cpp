class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        //brute force
        // int n=nums.size();
        // vector<int> prefix(n,0);//to store prefix in array
        // vector<int> suffix(n,0); //to store suffix in array
        // for(int i=1; i<n; i++){
        //     prefix[i]=prefix[i-1]+nums[i-1];
        // }
        // for (int i = n - 2; i >= 0; i--) {
        //     suffix[i] = suffix[i + 1] + nums[i + 1];
        // }
        // for(int j=0; j<n; j++){
        //     if(prefix[j]==suffix[j]){
        //         return j;
        //     }
        // }
        // return -1;    

        //optimised soln
        int n=nums.size();
        int right=0;    
        for(int i=0; i<n; i++){
            right+=nums[i];
        }//right will have total sum of the array

        int left=0;
        for(int i=0; i<n; i++){
            right-=nums[i];
            if(left==right){
                return i;
            }
            left+=nums[i];

        }
        return -1;
    }
};