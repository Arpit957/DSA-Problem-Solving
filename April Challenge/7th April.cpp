   class Solution {
public:
   void dfs(vector<vector<int>>& a, int i, int j) {
        if (i < 0 || j < 0 || i == a.size() || j == a[i].size() || a[i][j] != 1) return;
        a[i][j] = 0;
        dfs(a, i + 1, j);
        dfs(a, i - 1, j);
        dfs(a, i, j + 1);
        dfs(a, i, j - 1);
    }

    int numEnclaves(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();

        // To make all enclaves connected to edges visited
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i == 0 || j == 0 || i == n-1 || j == m-1)
                {
                    if(a[i][j] == 1)
                    dfs(a,i,j);
                }
            }
        }

        // To calculate number of unvisited enclaves
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(a[i][j] == 1)
                cnt++;
            }
        }

        return cnt;
    }
};
