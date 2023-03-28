class Solution {
    private:
    int solve(int n,vector<int>& days, vector<int>& costs,int index,vector<int>&dp){
        
        //base case
        if(index>=n)return 0;
        
        //3rd sttep
        if(dp[index]!=-1)return dp[index];
        
        //if we take 1 day pass
        int option1 = costs[0] + solve(n,days,costs,index+1,dp);
        
        
        //to take 7 days plan
        
        //to check whether the days are incomplete or not
        int i;
        for(i = index;i<n&& days[i]<days[index]+7;i++);
        
        int option2 = costs[1] + solve(n,days,costs,i,dp);
        
        //30 days plan
        for(i = index;i<n&& days[i]<days[index]+30;i++);
        
        int option3 = costs[2] + solve(n,days,costs,i,dp);
        
        dp[index] = min(option1,min(option2,option3));
        
        return dp[index];
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n+1,-1);
        return solve(n,days,costs,0,dp);
    }
};
