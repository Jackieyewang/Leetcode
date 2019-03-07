class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if(nums.empty())return{};
        sort(nums.begin(), nums.end());
        if(nums[0]>target || nums[n-1]<target || n<4)return {};
        vector<vector<int>> res;
        for (int i=0;i<n-3;++i){
            if(i>0&&nums[i]==nums[i-1])continue;
            if(nums[i]>target)return res;
            for(int j=i+1;j<n-2;++j){
                if(j>i+1&&nums[j]==nums[j-1])continue;
                int mid = nums[i]+nums[j]; 
                if(mid>target)return res;
                int left = j+1,right = n-1;
                while(left<right){
                    int sum = nums[left]+nums[right]+mid;
                    if(left>j+1&&nums[left]==nums[left-1]||sum<target)++left;
                    if(right<n-1&&nums[right]==nums[right+1]||sum>target)--right;
                    if(sum==target){
                        res.push_back({nums[i],nums[j],nums[left],nums[right]});
                        ++left;--right;
                   }
                }
            }
        }
        return res;
    }
};

/*这才运行正确，原代码找不到bug

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < int(nums.size() - 3); ++i) {
            for (int j = i + 1; j < int(nums.size() - 2); ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1, right = nums.size() - 1;
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        vector<int> out{nums[i], nums[j], nums[left], nums[right]};
                        res.insert(out);
                        ++left; --right;
                    } else if (sum < target) ++left;
                    else --right;
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};*/