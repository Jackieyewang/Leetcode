class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sum=0, cut, fin=INT_MAX-1;
        int n = nums.size();
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    cut = nums[k]+nums[i]+nums[j];
                        //cout << nums[i] <<";"<< nums[j]<<";"<< nums[k]<<"=>"<<cut << "-->"<<abs(cut-target)<< "**"<<fin <<endl;
                    if(abs(cut-target)<fin){
                        fin = abs(cut-target);
                        cout << fin <<endl;
                        sum = nums[i]+nums[j]+nums[k];
                    }
            
                }
            }
        }
        return sum;
    }
};