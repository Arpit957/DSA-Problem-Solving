class Solution {
public:
    int search(vector<int>& nums, int target) {
           int startIndex = 0; 
        int lastIndex = nums.size() - 1;
        while(startIndex <= lastIndex){
            //helps to prevent from out of bound
            int midIndex = (startIndex + (lastIndex - startIndex) / 2);
            if(nums[midIndex] == target){
                return midIndex;
            }
            else if(nums[midIndex] > target){
                lastIndex = midIndex - 1;
            }
            else{
                startIndex = midIndex + 1;
            }
        }
        return -1; 
    }
};