class Solution {
        void dfs(int node, unordered_map<int,vector<int>> &adj, vector<int> &vis){
    vis[node]=1;
    for(auto child:adj[node]){
        if(!vis[child]) dfs(child,adj,vis);
    }
}
bool areSimilar(string &x, string &y){
    int diff=0;
    for(int i=0;i<x.length();i++){
        if(x[i]!=y[i]) diff++;
    }
    return (diff==0 or diff==2);
}
public:
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        unordered_map<int,vector<int>> adj;
        //vector<vector<int> >adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(areSimilar(strs[i],strs[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                ans++;
            }
        }
        return ans;
    }
};
