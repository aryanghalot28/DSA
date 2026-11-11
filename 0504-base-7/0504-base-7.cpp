class Solution {
public:
    string convertToBase7(int num) {
        if(num==0)  return "0" ;
        string ans="";
        bool neg = num < 0;
        num = abs(num);
        while(num!=0){
            int digit = num%7;
            num = num/7;
            ans += to_string(digit);
        }
        reverse(ans.begin(), ans.end());
        if(neg)   return "-" + ans;
        else    return ans;



        
    }
};