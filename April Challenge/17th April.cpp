class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>ans(candies.size());
        priority_queue<int>pq;
        for(auto i:candies){
          pq.push(i);
        }
        int maxi = pq.top();

        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies >= maxi){
              ans[i] = true;
            }
            else{
                ans[i] = false;
            }
        }

        return ans;
    }
};
