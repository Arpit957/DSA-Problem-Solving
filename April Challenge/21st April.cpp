class Solution {
     int mod=1e9+7;
    int solve(int i,int n,int minProfit, vector<int>& group, vector<int>& profit,int curr_profit,int curr_members,vector<vector<vector<int>>>&dp){
        if(i==group.size()){
            return curr_profit>=minProfit;
        }
        if(dp[i][curr_profit][curr_members]!=-1)
        return dp[i][curr_profit][curr_members];
        int ans = 0;

 ans+= solve(i+1,n,minProfit,group,profit,curr_profit,curr_members,dp);

        if(curr_members+group[i]<=n){
            ans+= solve(i+1,n,minProfit,group,profit,min(curr_profit+profit[i],minProfit),curr_members+group[i],dp);
        }
        return dp[i][curr_profit][curr_members]=(ans)%mod;
    }
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
         vector<vector<vector<int>>> dp(101, vector<vector<int>>(101, vector<int>(101, -1)));
       return solve(0,n,minProfit,group,profit,0,0,dp);
    }
};
