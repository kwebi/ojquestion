#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int N = 5e5 + 50;
char a_new[N * 2];
int p[N];

int init(string &a, char a_new[], int S, int E)
{
    a_new[0] = '$';
    a_new[1] = '#';
    int j = 2;

    for (int i = S; i <= E; ++i)
    {
        a_new[j++] = a[i];
        a_new[j++] = '#';
    }
    return j;
}

int manacher(string &a, char a_new[], int S, int E)
{
    int len = init(a, a_new, S, E);
    int max_len = -1;
    int id;
    int mx = 0;
    for (int i = 1; i < len; ++i)
    {
        if (i < mx)
        {
            p[i] = min(p[2 * id - i], mx - i);
        }
        else
            p[i] = 1;
        while (a_new[i - p[i]] == a_new[i + p[i]])
            ++p[i];
        if (mx < i + p[i])
        {
            id = i;
            mx = i + p[i];
        }
        max_len = max(max_len, p[i] - 1);
    }
    return max_len;
}

int main()
{
    string a;
    getline(cin, a);
    int len = a.size();
    a += a;
    int ans = 0;
    for (int i = 0; i < len; ++i)
    {
        ans = max(ans, manacher(a, a_new, i, i + len - 1));
    }
    printf("%d\n", ans);
    return 0;
}
