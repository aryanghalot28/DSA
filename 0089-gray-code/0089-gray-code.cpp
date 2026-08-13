class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> temp;
        int ans= 1<<n;
        for(int i=0;i<ans;i++){
            int gray =i^(i>>1);
            temp.push_back(gray);

        }
        return temp;
        
    }
};