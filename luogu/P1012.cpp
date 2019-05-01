#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    string s[30];
    for (int i = 0; i < n; ++i)
    {
        int t;
        scanf("%d", &t);
        char st[100];
        sprintf(st, "%d", t);
        s[i].append(st);
    }
    sort(s, s + n, [](string &a, string &b) -> bool {
        return a + b > b + a;
    });
    for (int i = 0; i < n; ++i)
    {
        cout << s[i];
    }
    cout << endl;
    return 0;
}
