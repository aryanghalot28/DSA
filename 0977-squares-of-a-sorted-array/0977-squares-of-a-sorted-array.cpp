class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        for(int i=0; i<nums.size(); i++){    //this is to create 2 aarays pos and neg
            if(nums[i] >= 0){
                pos.push_back(nums[i]);
            }
            else{
                neg.push_back(nums[i]);
            }
        }
        if(pos.size() == 0){   //mtlb sirf negative elements hain
            for(int i=0; i<nums.size(); i++){
                nums[i] = nums[i]*nums[i];
            }
            reverse(nums.begin(), nums.end());
            return nums;
        }

        if(neg.size() == 0){    //means only pos elements are there
            for(int i=0; i<nums.size(); i++){
                    nums[i]=nums[i]*nums[i];
            }
            return nums;
        }

        int i=0; 
        int j=0;
        int id=0;
        int n = pos.size();
        int m = neg.size();
        vector<int> combinedarr(n+m);
        for(int i=0; i<n; i++){
            pos[i]=pos[i]*pos[i];
        }
        for(int i=0; i<m; i++){
            neg[i]=neg[i]*neg[i];
        }
        reverse(neg.begin(), neg.end());

        while(i<n && j<m){
            if(pos[i] <=neg[j]){
                combinedarr[id]=pos[i];
                id++;
                i++;
            }
            else{
                combinedarr[id]=neg[j];
                id++;
                j++;
            }
        }
        while(i<n){
            combinedarr[id]=pos[i];
            id++;
            i++;
        }
        while(j<m){
            combinedarr[id]=neg[j];
            id++;
            j++;
        }
        return combinedarr;
        
    }
};