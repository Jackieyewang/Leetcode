class Solution {
public:
    bool isPalindrome(int x) {
        int n = 0;
       // cout << x  << endl;
        if(x<0)return false;
        else if(x == 0) return true;
        int tmp = x,xx=x;
        while(tmp > 0){
            tmp /= 10;
            n++;
        }
        
        string t[n];
        for(int j=0;j<n;j++){
            t[j]=xx%10;
            xx /= 10;
        }
       // cout << n <<endl;
        
            for(int i=0;i<n-i-1;i++){
                if(t[i]!=t[n-i-1])return false;
            }
        return true;
    }
};