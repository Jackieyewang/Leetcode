class Solution { 
public:
    int myAtoi(string str) {
        int n = str.size();
        bool isPositive = 1;
        int res = 0,sign = 1;
        int b = 0;
        while (str[b] == ' ') ++b;
        for(int i=b;i<n;i++){
            if(str[i] == '-' || str[i] == '+') 
            {
                if(str[i+1] >= '0' && str[i+1] <= '9')sign = (str[i] == '+')?1:-1;
                else return 0;
            }
            else if(str[i] >= '0' && str[i] <= '9') {
                if (res > INT_MAX / 10 || (res == INT_MAX / 10 && str[i] - '0' > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
                }
                res = res*10 +(str[i]-'0');
                if(i+1 < n &&(str[i+1] < '0' || str[i+1] > '9'))break;
            }
            else break;
            }
        return res*sign;
    }
};