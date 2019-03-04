class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n==0) return "";
        string res = "";
        for(int i=0;i<strs[0].size();i++){
            char tmp = strs[0][i];
            for(int j=0;j<n;j++){
                if(i>strs[j].size()-1 || strs[j][i]!=tmp)return res;
                }
             res += strs[0][i];
            }
           
        return res;
    }
};