#include <iostream>
using namespace std;

int n;
int prize[1000];
int prizeoo[1000];

void get_input(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> prize[i];
    }
}

void second(){
    for(int i=0;i<n;i++){
        if(i==0)prizeoo[i] = (prize[0]+prize[1])/2;
        else if(i==n-1)prizeoo[i] = (prize[n-1]+prize[n-2])/2;
        else{
            prizeoo[i] = (prize[i-1]+prize[i]+prize[i+1])/3;
        }
    }
}

int main(){
    get_input();
    second();
    for(int i=0;i<n;i++)cout << prizeoo[i] <<" ";
}