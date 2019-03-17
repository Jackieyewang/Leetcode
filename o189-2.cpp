/*自码 错误的解法，不知道错在哪里*/

/*
// #include <iostream>
// using namespace std;

// int n;
// int H[2000][2];
// int W[2000][2];
// long long t;
// void get_input(){
//     cin >> n;
//     for(int i=0;i<n;i++){
//         cin >> H[i][0] >>H[i][1];
//     }
//     for(int j=0;j<n;j++){
//         cin >> W[j][0] >>W[j][1];
//     }    
// }

// void talktimer(){
//     t = 0;
//     for(int i=0;i<n;i++){
//         for(int j=i;j<n;j++){
//             if(H[i][1]>W[j][0]){
//                 int start = (H[i][0]<=W[i][0])?W[i][0]:H[i][0];
//                 int end = (H[i][1]<=W[i][1])?H[i][1]:W[i][1];
//                 t += end - start;
//                 break;
//             }
//         }
//     }
// }

// int main(){
//     get_input();
//     talktimer();
//     cout << t;
// }



/**************************************************************/
/*标记的解法，完美*/
#include<iostream>
 
using namespace std;
 
const int N=1000005;
int a[N];
 
int main()
{
	int n,x,y;
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++){
		scanf("%d%d",&x,&y);
		for(int j=x;j<y;j++)
		  a[j]++;
	}
	long long ans=0;
	for(int i=1;i<N;i++)
	  if(a[i]==2)
	    ans++;
	printf("%lld\n",ans);
	return 0;
} 

/*节省时空的解法*/

/*
#include<iostream>
 
using namespace std;
 
const int N=2005;
struct Time{
	int x,y;
}h[N],w[N];
 
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d%d",&h[i].x,&h[i].y);
	for(int i=1;i<=n;i++)
	  scanf("%d%d",&w[i].x,&w[i].y);
	long long ans=0;
	for(int i=1,j=1;i<=n&&j<=n;){//i和j分别表示当前小H和小W的第几个时间 
		//情况1 : w[j].x<h[i].x
		if(w[j].x<h[i].x){
			if(w[j].y<=h[i].x)
			  j++;
			else if(h[i].x<w[j].y&&w[j].y<h[i].y){
				ans+=w[j].y-h[i].x;
				j++;
			}
			else{
				ans+=h[i].y-h[i].x;
				i++;
			}
		}
		//情况二 : h[i].x<=w[j].x<h[i].y
		else if(h[i].x<=w[j].x&&w[j].x<h[i].y) {
			if(w[j].y<h[i].y){
				ans+=w[j].y-w[j].x;
				j++;
			}
			else if(w[j].y>=h[i].y){
				ans+=h[i].y-w[j].x;
				i++;
			}
		}
		//情况三 : w[j].x>=h[i].y
		else
		  i++;
	}
	printf("%lld\n",ans);
	return 0; 
}
*/













