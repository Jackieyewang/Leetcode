class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int,int> m;
        int n = s.size();
        int over = 0;
        int res = 0;
        for(int i=0;i<n;i++){
            if(m.count(s[i])){
                over += 1;
            }
        m[s[i]] = 1;
        }
        res = n - over;
        return res;
    }
};