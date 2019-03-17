#include <iostream>
#include <stdio.h>
using namespace std;

int n;
int array[10000];

void get_input(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> array[i];
    }
}

void caculate(){
    int tmp = array[0],num=0,numt;
    for(int i=0;i<n;i++){
        numt = 0;
        for(int j=0;j<n;j++){
            //if(j<i&&array[j] == array[i])break;
            if(array[j] == array[i])numt++;
        }
        if(numt>num){
            num = numt;
            tmp = array[i];
            }
        else if(numt == num ){
            if(array[i]<tmp)
            tmp = array[i];
        }
    }
    cout << tmp <<endl;
}

int main(){
    get_input();
    caculate();
    return 1;
}