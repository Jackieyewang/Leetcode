/*
问题描述
　　给定一个R行C列的地图，地图的每一个方格可能是'#', '+', '-', '|', '.', 'S', 'T'七个字符中的一个，分别表示如下意思：
　　'#': 任何时候玩家都不能移动到此方格；
　　'+': 当玩家到达这一方格后，下一步可以向上下左右四个方向相邻的任意一个非'#'方格移动一格；
　　'-': 当玩家到达这一方格后，下一步可以向左右两个方向相邻的一个非'#'方格移动一格；
　　'|': 当玩家到达这一方格后，下一步可以向上下两个方向相邻的一个非'#'方格移动一格；
　　'.': 当玩家到达这一方格后，下一步只能向下移动一格。如果下面相邻的方格为'#'，则玩家不能再移动；
　　'S': 玩家的初始位置，地图中只会有一个初始位置。玩家到达这一方格后，下一步可以向上下左右四个方向相邻的任意一个非'#'方格移动一格；
　　'T': 玩家的目标位置，地图中只会有一个目标位置。玩家到达这一方格后，可以选择完成任务，也可以选择不完成任务继续移动。如果继续移动下一步可以向上下左右四个方向相邻的任意一个非'#'方格移动一格。
　　此外，玩家不能移动出地图。
　　请找出满足下面两个性质的方格个数：
　　1. 玩家可以从初始位置移动到此方格；
　　2. 玩家不可以从此方格移动到目标位置。
输入格式
　　输入的第一行包括两个整数R 和C，分别表示地图的行和列数。(1 ≤ R, C ≤ 50)。
　　接下来的R行每行都包含C个字符。它们表示地图的格子。地图上恰好有一个'S'和一个'T'。
输出格式
　　如果玩家在初始位置就已经不能到达终点了，就输出“I'm stuck!”（不含双引号）。否则的话，输出满足性质的方格的个数。
样例输入
5 5
--+-+
..|#.
..|##
S-+-T
####.
样例输出
2
样例说明
　　如果把满足性质的方格在地图上用'X'标记出来的话，地图如下所示：
　　--+-+
　　..|#X
　　..|##
　　S-+-T
　　####X
*/

#include <iostream>
#include <map>
#include <queue>
#include <cstring>
 
using namespace std;
 
const int maxn = 55;
char G[maxn][maxn];
int vis[2][maxn][maxn];
int r,c;
int sx,sy,ex,ey;
map<char,int> m,m1;
 
void initmap () {
    m.insert(make_pair('+',4));m1.insert(make_pair('+',0));
    m.insert(make_pair('-',2));m1.insert(make_pair('-',1));
    m.insert(make_pair('|',2));m1.insert(make_pair('|',2));
    m.insert(make_pair('.',1));m1.insert(make_pair('.',3));
}
int f[4][4][2] = {
    0,1,0,-1,-1,0,1,0,
    0,1,0,-1,0,0,0,0,
    -1,0,1,0,0,0,0,0,
    1,0,0,0,0,0,0,0
};
 
struct Node {
    int x,y;
    Node(int a,int b):x(a),y(b) {}
};
 
bool check1 (int x,int y,int type) {
    if (x>=1 && x<=r && y>=1 && y<=c && G[x][y]!='#' && !vis[type][x][y])
        return true;
    else
        return false;
}
 
void bfs1 (int type , int x , int y) {
    if (type)
        memset(vis[type],0,sizeof(vis[type]));
    queue<Node> q;
    q.push(Node(x,y));
    vis[type][x][y] = 1;
 
    while (!q.empty()) {
        Node t = q.front() ; q.pop();
        int x = t.x , y = t.y;
        for (int i = 0 ; i < m[G[x][y]] ; i++) {
            int tx = x+f[m1[G[x][y]]][i][0];              
            int ty = y+f[m1[G[x][y]]][i][1];       
            if (check1(tx,ty,type)) {
                vis[type][tx][ty] = 1;
                q.push(Node(tx,ty));
            }
        }
        if (type && vis[type][ex][ey])
            break;
    }
}
 
int main () {
    int ans = 0;
    cin >> r >> c;
    for (int i = 1 ; i <= r ; i++) 
        for (int j = 1 ; j <= c ; j++) {
            char tmp;
            cin >> tmp;
            if (tmp == 'S') {sx=i;sy=j;tmp='+';}
            else if (tmp == 'T') {ex=i;ey=j;tmp='+';}
            G[i][j] = tmp;
        }
    initmap();
    bfs1(0,sx,sy);
 
    if (!vis[0][ex][ey]) {
        cout << "I'm stuck!" << endl;
        return 0;
    }
 
    vis[0][sx][sy] = vis[0][ex][ey] = 0;
    for (int i = 1 ; i <= r ; i++) 
        for (int j = 1 ; j <= c ; j++) {
            if (vis[0][i][j]) {
                bfs1(1,i,j);
                if (!vis[1][ex][ey]) 
                    ans++;
            }
        }
    cout << ans << endl;
    return 0;
}