class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        const int up = 0;
        const int down = 1;
        string res;
        int r = 0;
        int dir = down;
        vector<string> vec(numRows);
        for (int i = 0; i < s.size(); i++)
        {
            vec[r].push_back(s[i]);
            if (dir == down)
            {
                r++;
            }
            if (dir == up)
            {
                r--;
                c++;
            }
            if (r == numRows - 1)
            {
                dir = up;
            }

            if (r == 0)
            {
                dir = down;
            }
        }
        for (auto v : vec)
        {
            res += v;
        }
        return res;
    }
};
