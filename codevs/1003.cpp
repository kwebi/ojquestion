#include<stdio.h>
#include <vector>
using namespace std;

const int bound = 105;
int arr[105][105];
bool visited[105];
int w[105]; //每个顶点最短路径
int b[105]; //每个顶点的指向
vector<pair<int, int> > res;
long long sum = 0;

void prim(int arr[][bound], bool visited[], int w[], int b[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        visited[i] = false;
        w[i] = arr[i][0];
        b[i] = 0;
    }

    visited[0] = true;
    for (int i = 0; i < n; ++i)
    {
        int min = 10005;
        int j = 0;
        for (int m = 1; m < n; ++m)
        {
            if (!visited[m] && w[m] < min) //得到到访问顶点到未访问顶点的最短路径以及对应顶点j
            {
                min = w[m];
                j = m;
            }
        }
        visited[j] = true;
        if (arr[j][b[j]] != 0)
        {
            res.push_back(make_pair(j + 1, b[j] + 1));
            sum += arr[j][b[j]];
        }
        for (int m = 1; m < n; ++m)
        {
            if (!visited[m] && arr[j][m] < w[m])
            {
                w[m] = arr[j][m];
                b[m] = j;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    prim(arr, visited, w, b, n);
    printf("%d\n", res.size());
    for (int i = 0; i < res.size(); ++i)
    {
        int min = res[i].first < res[i].second ? res[i].first : res[i].second;
        int max = res[i].first > res[i].second ? res[i].first : res[i].second;
        printf("%d %d\n", min, max);
    }
    printf("%lld", sum);
    return 0;
}
