class Solution {
public:
    string intToRoman(int num) {
        string res;
        int n = 0, tmp = num, i = 0, k = 0;
        while(tmp > 0){
            tmp /= 10;
            n++;
        }
        int s[n];
        while(num > 0){
            s[i] = num % 10;
            num /= 10;
            i++;
        }
        for(int j = n-1;j>=0;j--){
            if(j==3)
            for(k=0;k<s[j];k++)res += "M";
            else if(j==2){
                if(s[j]==9)res += "CM";
                else if(s[j]>4 && s[j]<9){
                    res += "D";
                    for(k=0;k<s[j]-5;k++)res += "C";
                }
                else if(s[j]==4)res += "CD";
                else if(s[j]>0 && s[j] < 4){
                    for(k=0;k<s[j];k++)res += "C";
                }
            }
            else if(j==1){
                if(s[j]==9)res += "XC";
                else if(s[j]>4 && s[j]<9){
                    res += "L";
                    for(k=0;k<s[j]-5;k++)res += "X";
                }
                else if(s[j]==4)res += "XL";
                else if(s[j]>0 && s[j] < 4){
                    for(k=0;k<s[j];k++)res += "X";
                }
            }
            else if(j==0){
                if(s[j]==9)res += "IX";
                else if(s[j]>4 && s[j]<9){
                    res += "V";
                    for(k=0;k<s[j]-5;k++)res += "I";
                }
                else if(s[j]==4)res += "IV";
                else if(s[j]>0 && s[j] < 4){
                    for(k=0;k<s[j];k++)res += "I";
                }
            }
        }
        return res;
    }
};




/*简洁的方式
class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        vector<char> roman{'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        vector<int> value{1000, 500, 100, 50, 10, 5, 1};
        for (int n = 0; n < 7; n += 2) {
            int x = num / value[n];
            if (x < 4) {
                for (int i = 1; i <= x; ++i) res += roman[n];
            } else if (x == 4) {
                res = res + roman[n] + roman[n - 1]; 
            } else if (x > 4 && x < 9) {
                res += roman[n - 1];
                for (int i = 6; i <= x; ++i) res += roman[n];
            } else if (x == 9) {
                res = res + roman[n] + roman[n - 2];
            }
            num %= value[n];            
        }
        return res;
    }
};
*/


/*更简便
class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        vector<string> v1{"", "M", "MM", "MMM"};
        vector<string> v2{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> v3{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> v4{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return v1[num / 1000] + v2[(num % 1000) / 100] + v3[(num % 100) / 10] + v4[num % 10];
    }
};
*/
