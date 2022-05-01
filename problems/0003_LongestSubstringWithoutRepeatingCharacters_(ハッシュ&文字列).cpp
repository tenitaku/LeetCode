class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> index;
        int start = 0;
        int res = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (index.find(s[i]) != index.end() && index[s[i]] >= start) {
                start = index[s[i]] + 1;
            }
            index[s[i]] = i;
            res = max(res, i - start + 1);
        }
        return res;
    }
};

//わからん、30分考えてわからんかった...
