class Solution {
public:
    string longestPalindrome(string s) {
         int n = s.size();
         int len=0,start=0;
        for(int i=0;i<n-1;){
            if(n-i <= len/2)break;
            int left = i;
            int right = i;
            while(right<n-1 && s[right]==s[right+1])++right;
            i = right+1;
            while(right < n-1 && left > 0 && s[right+1]==s[left-1]){
                ++right;--left;
            }
            if(len < right-left+1){
                len = right-left+1;
                start = left;
            }

        }
        return s.substr(start,len);
    }
};
