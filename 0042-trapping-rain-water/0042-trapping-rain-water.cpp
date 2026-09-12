// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int total=0; 
//         int n=height.size();

//         vector<int> PrefixMax(n);
//         PrefixMax[0]=height[0];
//         for(int i=1; i<n-1;i++){
//             PrefixMax[i]=max(PrefixMax[i-1],height[i]);
//         }

//         vector<int> SuffixMax(n);
//         SuffixMax[n-1]=height[n-1];
//         for(int i=n-2; i>=0;i--){
//             SuffixMax[i]=max(SuffixMax[i+1],height[i]);
//         }

//         for(int i=0; i<n-1; i++){
//             int LeftMax=PrefixMax[i];
//             int RightMax=SuffixMax[i];
//             if(height[i]<LeftMax && height[i]<RightMax){
//                 total+=min(RightMax,LeftMax)-height[i];
//             }
//         }
//         return total;
//     }
// };

class Solution {
public:
    int trap(vector<int> &height){
        int leftmax=0;
        int rightmax=0;
        int total=0;
        int l=0;
        int r=height.size()-1;
        while(l<r){
            if(height[l] <= height[r]){
                leftmax=max(leftmax, height[l]);
                total+=leftmax-height[l];
                l++;
            }
            else{
                rightmax=max(rightmax, height[r]);
                total+=rightmax-height[r];
                r--;
            }
        }
        return total;
    }
};