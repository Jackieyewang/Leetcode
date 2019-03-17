#include <iostream>
using namespace std;

int n;
int h[1000];
void get_input(){
    for(int i=0;i<1000;i++)h[i]=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> h[i];
    }
}

int maxarea(){
    int res = 0,h_now;
    for (int i=0;i<n;i++){
        h_now = h[i];
        int left = 0,right = 0;
        if(i>0 && i<n-1){
            for(int k=i+1;k<n;k++){
                if(h[k]>=h_now)right++;
                else break;
            }
            for(int j=i-1;j>0;j--){
                if(h[j]>=h_now)left++;
                else break;
            }
        }
        else if(i == 0){
            for(int k=i+1;k<n;k++){
                if(h[k]>=h_now)right++;
                else break;
            }
        }
        else if(i == n-1){
            for(int j=i-1;j>0;j--){
                if(h[j]>=h_now)left++;
                else break;
            }
        }
        int len = right+left+1;
        if(len*h_now>res)res = len*h_now;
    }
    return res;
}

int main(){
    get_input();
    int m = maxarea();
    cout << m <<endl;
}