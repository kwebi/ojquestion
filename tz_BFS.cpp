#include<iostream>
using namespace std;

const int INF = 100000000;
typedef pair<int, int> P;
char maze[10][11];
int N, M;
int sx, sy;
int gx, gy;
int d[10][11];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs() {
    queue<P> que;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            d[i][j] = INF;
        }
    }
    que.push(P(sx, sy));
    while (que.size()) {
        P p = que.front();
        que.pop();
        if (p.first == gx && p.second == gy) {
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny <= M && maze[nx][ny] != '#' && d[nx][ny] == INF) {
                que.push(P(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    return d[gx][gy];
}

int main() {
    cin >> N >> M;
    cin >> sx >> sy;
    cin >> gx >> gy;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> maze[i][j];
        }
    }
    int res = bfs();
    cout << res << endl;
    return 0;
}