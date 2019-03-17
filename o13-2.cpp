#include <iostream>
#include <stdio.h>
using namespace std;

int num[10];
char str[13];
void get_input(){
    cin >> str ;
    int j = 0;
    for(int i=0;i<13;i++){
        if(str[i]!='-'){
            num[j] = str[i] - '0';
            j++;
        }
    }
}

char caculate(){
    int sum = 0,res = 0;
    for(int i=0;i<9;i++){
        sum += (i+1)*num[i];
    }
    res = sum % 11;
    if(res == 10)return 'X';
    return res+'0';
}

int main(){
    get_input();
    char chr = caculate();
    if(chr == str[12]) cout << "RIGHT" <<endl;
    else {
        str[12] = caculate();
        cout << str <<endl;
    }
    return 1;
}