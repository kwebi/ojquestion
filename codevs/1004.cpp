#include <map>

using namespace std;
/*
bfs三步走,入队,设置走法,去重判断.
最好在新的状态入队的判断.
*/

typedef long long LL;
map<LL,bool> h[3];
int dr[]= {0,0,1,-1},dc[]= {1,-1,0,0};


struct node {
    int dist,pre;
    LL hash_value;
    int map_[5][5];
};

bool check(node & a) {      //判断这个状态的棋盘是否形成连子
    for(int i=1; i<5; ++i)
        if(a.map_[i][1]==a.map_[i][2]&&a.map_[i][2]==a.map_[i][3]&&a.map_[i][3]==a.map_[i][4])
            return 1;
    for(int i=1; i<5; ++i)
        if(a.map_[1][i]==a.map_[2][i]&&a.map_[2][i]==a.map_[3][i]&&a.map_[3][i]==a.map_[4][i])
            return 1;
    if(a.map_[1][1]==a.map_[2][2]&&a.map_[2][2]==a.map_[3][3]&&a.map_[3][3]==a.map_[4][4])
        return 1;
    if(a.map_[4][1]==a.map_[3][2]&&a.map_[3][2]==a.map_[2][3]&&a.map_[2][3]==a.map_[1][4])
        return 1;
    return 0;
}