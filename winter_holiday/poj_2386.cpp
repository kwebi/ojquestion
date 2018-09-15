#include<cstdio>
#include<iostream>
using namespace std;

int N, M;
char field[105][105];

void dfs(int x, int y) {
    field[x][y] = '.';
    int dx, dy;
    for (dx = -1; dx <= 1; dx++) {
        for (dy = -1; dy <= 1; dy++) {
            int nx = x + dx;
            int ny = y + dy;
            if (0 <= nx && nx < N && 0 <= ny && ny < M && field[nx][ny] == 'W') {
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    scanf("%d%d", &N, &M);
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            cin >> field[i][j];
        }
    }
    int res = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (field[i][j] == 'W') {
                dfs(i, j);
                res++;
            }
        }
    }
    printf("%d\n", res);
    return 0;
}