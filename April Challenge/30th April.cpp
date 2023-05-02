class Solution {

    int findparent(vector<int>&parent,int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node] = findparent(parent,parent[node]);
    }
    
    void makeset(int edge1,int edge2,vector<int>&parent){
        int parent1 = findparent(parent,edge1);
        int parent2 = findparent(parent,edge2);
        parent[parent1] = parent2;
    }
    
int isvalid(int type,vector<vector<int>>& edges,vector<int>&parent)
   { 
     int count = 0;
    for(int i =0;i<edges.size();i++){
      if(type == edges[i][0] && findparent(parent,edges[i][1]) != 
                                  findparent(parent,edges[i][2])){
       count++;
       makeset(edges[i][1],edges[i][2],parent);
      }
    }
    return count;
}
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

       //no of edges 
       int edge = edges.size();
      //intitally mark everyone parent with itself
       vector<int>parent;
       for(int i=0;i<=n;i++){
          // parent[i] = i;
           parent.push_back(i);
       }
       
       //make graph only with type3
       int type3 = isvalid(3,edges,parent);
       
       
       vector<int>p = parent;
        //make graph only with type1
       int type1 = isvalid(1,edges,parent);
       //make graph only with type2

       //kyuki parent array type1 trversal ke baad change ho jayga
       parent = p;
       int type2 = isvalid(2,edges,parent);
    //    //make graph only with type1
    //    int type1 = isvalid(1,edges,parent);

      if(type1+type3 != n-1 || type2+type3 != n-1){
          return -1;
      }

      return edge-type1-type2-type3;
         
    }
};
