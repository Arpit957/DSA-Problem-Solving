/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int> >q;

        q.push(make_pair(root,0));

        int ans= INT_MIN;

        while(!q.empty()){
            int temp_index = q.front().second;

            int size = q.size();
            int index1,last_index;

            for(int i =0;i<size;i++){
                 TreeNode* node = q.front().first;
                 int curr_index = q.front().second;
                 
                 curr_index-=temp_index;
                 q.pop();

                 if(i==0){
                      index1 = curr_index;
                 }
                 if(i==size-1){
                     last_index = curr_index;
                 }

                 if(node->left){
                     q.push(make_pair(node->left,1ll*2*curr_index+1));
                 }
                  if(node->right){
                     q.push(make_pair(node->right,1ll*2*curr_index+2));
                 }   
            }

            ans = max(ans,last_index - index1 +1);
        }

        return ans;
    }
};
