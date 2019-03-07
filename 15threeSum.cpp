class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        int sum=1,lev=0;
        sort(nums.begin()nums.end());
        if(nums.empty()||nums[0]>0||nums[n-1]<0)return {};
        for(int k=0;k<n-2;k++){
            if(nums[k]>0)break;
            if(nums[k]==nums[k-1])continue;
            for(int i=k+1;i<n-1;i++){
                sum = nums[k]+nums[i];
                lev = 0 - sum;
                for(int j=i+1;j<n;){
                    if(nums[j]<0)j++;
                    else if(nums[j]==lev){
                        res.push_back({nums[k],nums[i],nums[j]});
                    }
                    j++;
                }
            }
        }
        return res;
    }
};