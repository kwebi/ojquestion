#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 5;
int ocur[30] = {0};
int nocur[30] = {0};
bool change[30] = {0};

char x[maxn];
char y[maxn];
vector<int> v[30];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    string name;
    cin >> name;
    for (int i = 0; i < n; ++i)
    {
        if (v[name[i] - 'a'].empty())
        {
            v[name[i] - 'a'].push_back(name[i] - 'a');
        }
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> x[i] >> y[i];
        int j1 = -1;
        int j2 = -1;
        for (int j = 0; j < 30; ++j)
        {
            if (v[j].empty())
                continue;
            if (v[j].back() == (x[i] - 'a'))
            {
                j1 = j;
            }
            if (v[j].back() == (y[i] - 'a'))
                j2 = j;
        }

        if (j1 != -1)
            v[j1].back() = y[i] - 'a';
        if (j2 != -1)
            v[j2].back() = x[i] - 'a';
    }
    for (int i = 0; i < n; ++i)
    {
        cout << char(v[name[i] - 'a'].back() + 'a');
    }
    cout << endl;

    return 0;
}
