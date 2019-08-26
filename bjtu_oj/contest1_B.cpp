#include <vector>
#include <stdio.h>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

bool used[30];

int main()
{
    memset(used, 0, sizeof(used));
    int k;
    cin >> k;
    string q;
    cin >> q;
    vector<string> res;
    int n = 0;
    int i;
    for (i = 0; i < q.size(); ++i)
    {
        if (n == k)
            break;
        if (!used[q[i] - 'a'])
        {
            string t;
            t.push_back(q[i]);
            res.push_back(t);
            ++n;
            used[q[i] - 'a'] = true;
        }
        else
        {
            res[res.size() - 1].push_back(q[i]);
        }
    }
    if (n < k)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        for (int j = i; j < q.size(); ++j)
        {
            res[res.size() - 1].push_back(q[j]);
        }
        for (int j = 0; j < res.size(); ++j)
        {
            cout << res[j] << endl;
        }
    }
    return 0;
}
