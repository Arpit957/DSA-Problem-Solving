class Solution {
private:  int m,n, mod = 1e9 + 7;
public:
    int calculateways(vector<string> &pizza, int k, int i, int j, vector<vector<vector<int>>> &dp) {
        // if k==1 and pizza is there return 1;
        // 0 otherwise
        if(i >= m || j>=n) return 0;
        if(dp[k][i][j]!=-1) return dp[k][i][j];
        if(k==1) {
            bool isapple = false;         
           for(int p=i;p<m;p++) 
                for(int q=j;q<n;q++) 
                    if(pizza[p][q]=='A') {isapple = true; break;}
            return isapple;
        }
        long long total = 0, mod = 1e9 + 7;        
        //horizontal cuts
        bool isapple = false;
        for(int p=i;p<m;p++) {
            for(int q=j;q<n && !isapple;q++) {
                if(pizza[p][q]=='A') isapple = true;
            }
            if(isapple) 
                total += calculateways(pizza, k-1, p+1, j, dp);        
        }
    //vertical cuts
        isapple = false;
        for(int q=j;q<n;q++) {
            for(int p=i;p<m && !isapple;p++) {
                if(pizza[p][q]=='A') isapple = true;
            }
            if(isapple)
                total += calculateways(pizza, k-1, i, q+1, dp);          
        }
        return dp[k][i][j] = total%mod;
    }
    int ways(vector<string>& pizza, int k) {
        m = pizza.size(), n = pizza[0].size();    
        vector<vector<vector<int>>> dp(k+1, vector<vector<int>>(m, vector<int>(n, -1)));
        return calculateways(pizza, k, 0, 0, dp);
    }
};
