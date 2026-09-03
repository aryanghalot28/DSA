class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string res;
        for(int i=0; i<s.size(); i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else if(s[i]!=st.top()){
                st.push(s[i]);
            }
            else{
                st.pop();
            }
        }
        while(!st.empty()){
            char c=st.top();
            st.pop();
            res.push_back(c);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};