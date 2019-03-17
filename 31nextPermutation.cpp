class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int j,i,n = nums.size();
        for(int i=n-2; i>=0;i--){
            if(nums[i+1]>nums[i]){
                for(j=n-1;j>i;j--){
                    if(nums[j]>nums[i])break;
                }
                    swap(nums[j],nums[i]);
                    reverse(nums.begin()+i+1,nums.end());
                    return;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};