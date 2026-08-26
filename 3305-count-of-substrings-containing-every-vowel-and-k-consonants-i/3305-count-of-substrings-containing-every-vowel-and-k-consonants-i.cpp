class Solution {
public:
    long long atMost(string s, int k) {
        if(k < 0)
            return 0;
        int left = 0;
        int con = 0;
        long long ans = 0;
        unordered_map<char, int> mpp;

        for(int right = 0; right < s.size(); right++) {
            if(s[right] == 'a' || s[right] == 'e' ||
               s[right] == 'i' || s[right] == 'o' ||
               s[right] == 'u') {
                mpp[s[right]] = right;
            }
            else {
                con++;
            }

            while(con > k) {
                if(s[left] != 'a' && s[left] != 'e' &&
                   s[left] != 'i' && s[left] != 'o' &&
                   s[left] != 'u') {
                    con--;
                }

                left++;
            }

            if(mpp.size() == 5) {
                int mn = min({
                    mpp['a'],
                    mpp['e'],
                    mpp['i'],
                    mpp['o'],
                    mpp['u']
                });

                if(mn >= left)
                    ans += mn - left + 1;
            }
        }
        return ans;
    }
    long long countOfSubstrings(string word, int k) {
        return atMost(word, k) - atMost(word, k - 1);
    }
};