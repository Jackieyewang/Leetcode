class Solution {
public:
    int divide(int dividend, int divisor) {
        int sha=0;
        int sign1 = 1,sign2 = 1;
        if(dividend<0)sign1=-1;
        if(divisor<0)sign2=-1;
        if(sign1==1&&sign2==1){
            while(dividend>=divisor){
                dividend -= divisor;
                sha++;
            }
        }
        else if(sign1==-1&&sign2==1){
            if(dividend==INT_MIN&&divisor==1)return INT_MIN;
            while(dividend<=-abs(divisor)){
                dividend += divisor;
                sha++;
            }
        }
        else if(sign1==1&&sign2==-1){
            if(divisor==INT_MIN)return 0;
            while(dividend>=abs(divisor)){
                dividend += divisor;
                sha++;
            }
        }
        else if(sign1==-1&&sign2==-1){
            if(divisor==INT_MIN){
                if(dividend==INT_MIN)return 1;
                else return 0;
            };
            if(dividend==INT_MIN&&divisor==-1)return INT_MAX;
            while(dividend<=divisor){
                dividend -= divisor;
                sha++;
            }
        }
        return sha*sign1*sign2;
    }
};