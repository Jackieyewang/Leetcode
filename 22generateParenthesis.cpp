class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        he(n,n,"",res);
        return res;
    }
    void he(int left, int right,string strs,vector<string> &res){
        if(left>right)return;
        else if(left==0&&right==0)res.push_back(strs);
        else{
            if(left>0)he(left-1,right,strs+'(',res);
            if(right>0)he(left,right-1,strs+')',res);
        }
    }
};