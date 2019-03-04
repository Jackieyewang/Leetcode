#include <iostream>
#include <vector>

class solution{
    public:
        vector<int> twosum(vector<int>& nums,int target){
            map<int,int> m;
            vector<int> res;
            for(int i = 0;i < nums.size();i++){
                m[nums[i]] = i;
            }
            for(i = 0;i < nums.size(); i++){
                int t = target - nums[i];
                if(m.count(t) && m[t]!= i){
                    res.push(i);
                    res.push(m(t));
                }
                break;
            }
            return res;
        }
};