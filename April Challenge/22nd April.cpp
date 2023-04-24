class Solution {
public:
  int longestPalindromeSubstring(string& s, int i, int j, vector<vector<int>>& dp) {
        if (i > j)
            return 0;
        else if (i == j)
            return 1;
        else if (dp[i][j] != -1)
            return dp[i][j];
        else if (s[i] == s[j])
            return dp[i][j] = 2 + longestPalindromeSubstring(s, i+1, j-1, dp);
        else
            return dp[i][j] = max(longestPalindromeSubstring(s, i+1, j, dp), longestPalindromeSubstring(s, i, j-1, dp));
    }
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(502, vector<int>(502, -1));
        int minNumSteps = n - longestPalindromeSubstring(s, 0, n-1, dp);
        return minNumSteps;   
    }
};
