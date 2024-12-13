#include <iostream>
using namespace std;
class Solution {
public:
	bool isMatch(string s, string p) {
		//return isMatch_recursive(s, 0, p, 0);
		//return isMatch_bottomup(p, p.size(), s, s.size());
		vector<vector<int>> dp(1 + s.size(), vector<int>(1 + p.size(), -1));
		return isMatch_topdown(s, 0, p, 0, dp);
	}

	bool isMatch_recursive(string s, int i, string p, int j)
	{
		if (i >= s.size() && j >= p.size()) return true;
		if (j >= p.size()) return false;

		bool match = (i < s.size()) && (p[j] == '.' || p[j] == s[i]);

		if (j + 1 < p.size() && p[j + 1] == '*')
		{
			return (isMatch_recursive(s, i, p, j + 2)  // do not use *
				|| (match && isMatch_recursive(s, i + 1, p, j)));   // use *, if you use *, the letter before * must match.
		}

		if (match)
		{
			return isMatch_recursive(s, i + 1, p, j + 1);
		}

		return false;
	}


	bool isMatch_topdown(string s, int i, string p, int j, vector<vector<int>>& dp)
	{
		if (i >= s.size() && j >= p.size()) return true;
		if (j >= p.size()) return false;

		if (dp[i][j] != -1) return dp[i][j];

		bool match = (i < s.size()) && (p[j] == '.' || p[j] == s[i]);

		if (j + 1 < p.size() && p[j + 1] == '*')
		{
			dp[i][j] = (isMatch_topdown(s, i, p, j + 2, dp)  //
				|| (match && isMatch_topdown(s, i + 1, p, j, dp)));
			return dp[i][j];
		}

		if (match)
		{
			dp[i][j] = isMatch_topdown(s, i + 1, p, j + 1, dp);
			return dp[i][j];
		}

		dp[i][j] = false;
		return dp[i][j];
	}
};
