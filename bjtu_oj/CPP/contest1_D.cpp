#include <iostream>
#include <cstring>
#include <vector>
#include <stdio.h>

using namespace std;

const int maxn = 2e5 + 5;
char str[maxn];
vector<vector<int>> ans;
vector<int> v0; //以零结尾的行
vector<int> v1; //以1结尾的行

int main()
{
    scanf("%s", str);
    int len = strlen(str);

    bool val = bool(str[0] - '0');
    if (val == 1)
    {
        printf("-1\n");
        return 0;
    }
    ans.push_back(vector<int>{1});
    v0.push_back(0);
    for (int i = 1; i < len; ++i)
    {
        if (str[i] == '0')
        {
            if (v1.empty())
            {

                ans.push_back(vector<int>{i + 1});
                v0.push_back(ans.size() - 1);
            }
            else
            {
                ans[v1.back()].push_back(i + 1);

                v0.push_back(v1.back());
                v1.pop_back();
            }
        }
        else
        {
            if (v0.empty())
            {
                printf("-1\n");
                return 0;
            }
            else
            {
                ans[v0.back()].push_back(1 + i);
                v1.push_back(v0.back());
                v0.pop_back();
            }
        }
    }
    if (!v1.empty())
    {
        printf("-1\n");
        return 0;
    }

    cout << ans.size() << endl;
    for (auto &e : ans)
    {
        cout << e.size();
        for (auto ele : e)
        {
            cout << ' ' << ele;
        }
        cout << endl;
    }

    return 0;
}
