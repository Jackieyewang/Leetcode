class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int mid = (n-1)/2, left = 0, right = n-1,t = 0;
        if(nums.empty())return -1;
        while(t <(n+1)/2+1){
            cout << mid<<"," <<nums[mid] <<"t"<<t <<endl;
            if(nums[mid]>target){
                if(nums[left]<nums[mid]){
                    if(nums[left]<target){
                        right = mid;
                        mid = (left+mid)/2;
                        t++;
                        continue;
                    }
                    else if(nums[left]>target){
                        left = mid;
                        mid = (right + mid)/2;
                        t++;
                        continue;
                    }
                    else return left;
                }
                else if(nums[left]>nums[mid]){
                    right = mid;
                    mid = (left+mid)/2;
                    t++;
                    continue;
                }
                else mid = right;
                t++;
            }
            else if(nums[mid]<target){
                if(nums[right]>nums[mid]){
                    if(nums[right]>target){
                        left = mid;
                        mid = (right+mid)/2;
                        t++;
                        continue;
                    }
                    else if(nums[right]<target){
                        right = mid;
                        mid = (left + mid)/2;
                        t++;
                        continue;
                    }
                    else return right;
                }
                else if(nums[right]<nums[mid]){
                    left = mid;
                    t++;
                    mid = (right+mid)/2;
                    continue;
                }
                else mid = left;
                t++;
            }
            else return mid;
        }
        return -1;
    }
};

/************************better**********************************/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < nums[right]) {
                if (nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            } else {
                if (nums[left] <= target && nums[mid] > target) right = mid - 1;
                else left = mid + 1;
            }
        }
        return -1;
    }
};
/*******************************************************************/