class Solution {
public:
    bool isValid(string s) {
        stack<char> judge;
        for(int i=0;i<s.size();i++){
            if(s[i]=='{'||s[i]=='('||s[i]=='['){
                judge.push(s[i]);
            }
            else{
                if(judge.empty())return false;
                else if(s[i]==')'&&judge.top()!='(')return false;
                else if(s[i]==']'&&judge.top()!='[')return false;
                else if(s[i]=='}'&&judge.top()!='{')return false;
                judge.pop();
            }
            
        }
        return judge.empty();
    }
};