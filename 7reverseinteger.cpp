class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        int remainder = 0;
        int divisor = x;
        while(divisor !=0 ){
            remainder = divisor%10;
            divisor = divisor/10;
            if(abs(res)  > INT_MAX/10)return 0;
            res = res*10+remainder;
            }
        return res;
    }
};
