class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;;
        int res = 0, left = -1;
        for (int r = 0; r < s.size(); r++) {
            // update left pointer
          if (m.count(s[r])) {
            left = max(left, m[s[r]]);
          }
          res = max(res, r - left );
          m[s[r]] = r;
          std::cout << "right = " << r  << ", "  << s[r] << ", left = " << left << " " << s.substr(left, r - left) << ", length = " << r - left << std::endl;
        }
        return res;
    }
};
