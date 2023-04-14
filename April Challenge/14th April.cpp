class Solution {
   int solve(string &s,vector<vector<int>> &dp,int m,int n){
    if(m>=s.length() || n<0) return 0;
    
    if(dp[m][n]!=-1) return dp[m][n];
        
    if(s[m]==s[n])
        return dp[m][n]=1+solve(s,dp,m+1,n-1);
   
        else
    return dp[m][n]=max(solve(s,dp,m+1,n),solve(s,dp,m,n-1));
}
public:
int longestPalindromeSubseq(string s){ 
vector<vector<int>> dp(s.length(),vector<int> (s.length(),-1));
        
   return solve(s,dp,0,s.length()-1);
    }
};
