#include <algorithm>
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int used[25] = {0};
string s[25];
int n;
char head;
string ans;
string lastans;

int same(string &s1, string &s2)
{

    int res = min(s1.size(), s2.size());

    int flag = 0;

    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] != s2[0])
        {
            continue;
        }
        else
        {

            int j = 0;
            int k = i;
            while (s1[k] == s2[j] && j < s2.size() && k < s1.size())
            {
                j++;
                k++;
            }
            if (j == s2.size())
                continue;
            if (k == s1.size() && i != 0)
            {
                flag = 1;
                res = min(j, res);
            }
        }
    }
    if (flag == 1)
        return res;
    return 0;
}

void dfs(string &s1)
{
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (used[i] < 2)
        {
            int t = same(s1, s[i]);
            if (t > 0)
            {
                flag = true;
                ans += s[i].substr(t, s[i].size() - t);
                used[i]++;
                dfs(ans);
                used[i]--;
                for (int j = 0; j < s[i].size() - t; j++)
                    ans.pop_back();
            }
        }
    }
    if (!flag)
    {
        lastans = lastans.size() > ans.size() ? lastans : ans;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    cin >> head;
    for (int i = 0; i < n; i++)
    {
        if (s[i][0] == head)
        {
            ans += s[i];
            used[i]++;
            dfs(ans);
            used[i]--;
            for (int j = 0; j < s[i].size(); j++)
                ans.pop_back();
        }
    }

    cout << lastans.size() << endl;
    return 0;
}
