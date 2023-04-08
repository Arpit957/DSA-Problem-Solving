class Solution {
    
    void dfs(Node* node,Node* copy,vector<Node*>&vis){
        
        vis[copy->val]=copy;
        
        for(auto x :node->neighbors){
            if(vis[x->val]==NULL){
                Node* temp = new Node(x->val);
                (copy->neighbors).push_back(temp);
                dfs(x,temp,vis);
            }
            else{
                (copy->neighbors).push_back(vis[x->val]);
            }
        }
        
    }
    
public:
    Node* cloneGraph(Node* node) {
       
        
         if(node==NULL)return nullptr;
        
        Node* ans = new Node(node->val);
        
        vector<Node*>vis(101,nullptr);
        
        dfs(node,ans,vis);
        
        return ans;
        
    }
};
