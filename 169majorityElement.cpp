class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int m[n];
        for(int i=0;i<n;i++)m[n]=0;
        for(int i=0;i<n;i++){
            /*遍历字典的value？？？？？？*/
        }
    }
};



/********************************************************/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, cnt = 0;
        for (int num : nums) {
            if (cnt == 0) {res = num; ++cnt;}
            else (num == res) ? ++cnt : --cnt;
        }
        return res;
    }
};