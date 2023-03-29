class Solution {
    int solve(vector<int>& satisfaction,int index,int time){
        
        //base case
        if(index == satisfaction.size()){
            return 0;
        }
        
        //to add 1 in time it means a dish has been cooked
        //keep increasing index
int include = satisfaction[index] * (time+1)  + solve(satisfaction,index+1,time+1);
       //while we exclude them who has satisfa in negative
        int exclude = 0+ solve(satisfaction,index+1,time);
        
        return max(include,exclude);
    }
    
    
    int solve2(vector<int>& satisfaction,int index,int time,
               vector<vector<int> >&dp){
        
        //base case
        if(index == satisfaction.size()){
            return 0;
        }
        
        if(dp[index][time] != -1)return dp[index][time];
        
        
int include = satisfaction[index] * (time+1)  + solve2(satisfaction,index+1,time+1,dp);
       int exclude = 0 + solve2(satisfaction,index+1,time,dp);
        
        return dp[index][time]=max(include,exclude);
    }
    
    int solve3(vector<int>& satisfaction){
        
         int n = satisfaction.size();
        vector<vector<int> >dp(n+1,vector<int>(n+1,0));
        
        //bottom approach
        
        for(int index = n-1;index>=0;index--){
            for(int time = index;time>=0;time--){
                
        int include = satisfaction[index] * (time+1)+ dp[index+1][time+1];
       int exclude = 0+ dp[index+1][time];
        
         dp[index][time]=max(include,exclude);
            }
        }
        
        return dp[0][0];
    }
    
    int solve4(vector<int>& satisfaction){
        
         int n = satisfaction.size();
        //vector<vector<int> >dp(n+1,vector<int>(n+1,0));
        
        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);
     
        //bottom approach
      for(int index = n-1;index>=0;index--){
            for(int time = index;time>=0;time--){
                
        int include = satisfaction[index] * (time+1)+ next[time+1];
       int exclude = 0+ next[time];
        
         curr[time]=max(include,exclude);
            }
          
          next = curr;
       }
        
        return next[0];
    }
    
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        
        sort(satisfaction.begin(),satisfaction.end());
        
        //return solve(satisfaction,0,0);
        
        int n = satisfaction.size();
        
//         vector<vector<int > >dp(n,vector<int>(n,-1));
        
//         return solve2(satisfaction,0,0,dp);
        
        //return solve3(satisfaction);
        
        return solve4(satisfaction);
    }
};
