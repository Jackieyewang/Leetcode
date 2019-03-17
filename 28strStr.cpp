class Solution {
public:
    int strStr(string haystack, string needle) {
        int n_h = haystack.size(),n_n = needle.size();
        if(needle.empty())return 0;
        if(n_h < n_n) return -1;
        for(int i=0;i<=n_h-n_n;i++){
            if(haystack[i]==needle[0]){
                for(int j=0;j<needle.size();j++){
                    if(haystack[i+j]!=needle[j])break;
                    else if(haystack[i+j]==needle[j]&&j==needle.size()-1)return i;
                }
            }
            return -1;
        }
    }
};