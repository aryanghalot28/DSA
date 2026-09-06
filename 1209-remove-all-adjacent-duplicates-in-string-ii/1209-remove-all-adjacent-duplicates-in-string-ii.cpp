class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<char> st;
        stack<int> cnt;
        string res;
        for (int i = 0; i < s.size(); i++) {
            if (st.empty()) {
                st.push(s[i]);
                cnt.push(1);
            }
            else if (s[i] != st.top()) {
                st.push(s[i]);
                cnt.push(1);
            }
            else {
                cnt.top()++;
                if (cnt.top() == k) {
                    st.pop();
                    cnt.pop();
                }
            }
        }

        while (!st.empty()) {
            char c = st.top();
            int count = cnt.top();
            st.pop();
            cnt.pop();
            while (count--) {
                res.push_back(c);
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};