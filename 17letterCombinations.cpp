class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string dic[]={"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res{""};
        if(digits.empty())return {};
        for(int i=0;i<digits.size();i++){
            vector<string> mid;
            int tmp = digits[i]-'0';
            string str = dic[tmp-2];
            for(int j=0;j<str.size();j++){
                for(string s:res)mid.push_back(s+str[j]);
            }
            res = mid;
        }
        return res;
    }
};