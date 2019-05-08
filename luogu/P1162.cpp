#include <queue>
#include <stdio.h>
#include <iostream>
using namespace std;

int nx[4] = {1, -1, 0, 0};
int ny[4] = {0, 0, 1, -1};

int arr[35][35];
int b[35][35];
int n;

void dfs(int x, int y)
{
    if (x < 0 || x > n+1 || y < 0 || y > n+1 || arr[x][y] != 0)
        return;
    arr[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int tx = x + nx[i];
        int ty = y + ny[i];
        dfs(tx, ty);
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> b[i][j];
            if (b[i][j] == 0) arr[i][j]=0;
            else arr[i][j]=2;
        }
    }
    
    dfs(0,0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[i][j]==0)
            {
                cout << 2 << ' ';
            }
            else
            {
                cout << b[i][j] << ' ';
            }
        }

        cout << endl;
    }
    return 0;
}
