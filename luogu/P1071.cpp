#include <string>
#include <cstring>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    string a, b, c;
    cin >> a >> b >> c;
    char m[30];
    memset(m, '0', sizeof(m));
    bool fail = false;
    for (int i = 0; i < a.size(); ++i)
    {
        int ix = a[i] - 'A';
        if (m[ix] == '0')
            m[ix] = b[i];
        else
        {
            if (m[ix] != b[i])
            {
                fail = true;
                break;
            }
        }
    }
    int m1[30];
    memset(m1, 0, sizeof(m1));
    for (int i = 0; i < ('Z' - 'A') + 1; ++i)
    {
        if (m[i] == '0')
        {
            fail = true;
            break;
        }
        m1[m[i]-'A'] += 1;
    }
    for (int i = 0; i < ('Z' - 'A') + 1; ++i)
    {
        if (m1[i] != 1)
        {
            fail = true;
            break;
        }
    }
    string res;
    if (fail)
        printf("Failed");
    else
    {
        for (int i = 0; i < c.size(); ++i)
            res.push_back(m[c[i] - 'A']);
        cout << res << endl;
    }
    return 0;
}
