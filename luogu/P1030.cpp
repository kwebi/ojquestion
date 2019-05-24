#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char s1[10];
char s2[10];
int len;
int find(char ch)
{
    for (int i = 0; i < len; i++)
    {
        if (s1[i] == ch)
            return i;
    }
}
void dfs(int l1, int r1, int l2, int r2)
{
    int m = find(s2[r2]);
    cout << s2[r2];
    if (m > l1) /*具有左子树*/
        dfs(l1, m - 1, l2, r2 - r1 + m - 1);
    if (m < r1) /*具有右子树*/
        dfs(m + 1, r1, l2 + m - l1, r2 - 1);
}
int main()
{
    cin >> s1;
    cin >> s2;
    len = strlen(s1);
    dfs(0, len - 1, 0, len - 1);
    return 0;
}
