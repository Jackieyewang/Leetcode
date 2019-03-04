class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if (numRows <= 1) return s;
        string res = "";
        for(int i=0;i<numRows;i++){
            for(int j=0;i+2*j*(numRows-1)<n;j++){
                int num = i+2*j*(numRows-1);
                res += s[num];
                int numt = i+2*j*(numRows-1)+2*(numRows-1-i);
                if(i != 0 && i != numRows-1 && numt <n){
                    res += s[numt];
                    }
                }          
            }
        return res;
    }
};