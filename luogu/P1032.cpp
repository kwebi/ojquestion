#include <stdio.h>
#include <string>
#include <iostream>
#include <queue>
#include <map>

using namespace std;

string a1[6];
string b1[6];
string a, b;

struct node
{
    string str;
    int step;
};

int ans, n;

map<string, int> ma;

string trans(const string &str, int i, int j) //str的第i个字符是否满足第j个转换
{
    string ans = "";
    if (i + a1[i].length() > str.length())
        return ans;
    for (int k = 0; k < a1[j].length(); ++k)
    {
        if (str[i + k] != a1[j][k])
            return ans;
    }
    ans += str.substr(0, i);
    ans += b1[j];
    ans += str.substr(i + a1[j].length());
    return ans;
}

void bfs()
{
    queue<node> q;
    node s;
    s.str = a;
    s.step = 0;
    q.push(s);
    while (!q.empty())
    {
        node u = q.front();
        q.pop();
        string tmp;
        if (ma.count(u.str) == 1)
            continue;
        if (u.str == b)
        {
            ans = u.step;
            break;
        }
        ma[u.str] = 1;
        for (int i = 0; i < u.str.length(); ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                tmp = trans(u.str, i, j);
                if (tmp != "")
                {
                    node v;
                    v.str = tmp;
                    v.step = u.step + 1;
                    q.push(v);
                }
            }
        }
    }
    if (ans > 10 || ans == 0)
    {
        cout << "NO ANSWER!" << endl;
    }
    else
    {
        cout << ans << endl;
    }
}

int main()
{
    cin >> a >> b;
    n = 0;
    while (cin >> a1[n] && cin >> b1[n])
    {
        ++n;
    }
    bfs();
    return 0;
}
