#include <stdio.h>
#include <iostream>
using namespace std;

struct TNode
{
    char l;
    char r;
} a[130];

void print(char c)
{
    if (c == '*')
        return;
    cout << c;
    print(a[c].l);
    print(a[c].r);
}

int main()
{
    int n;
    scanf("%d", &n);
    char c1, c2, c3;
    cin >> c1 >> c2 >> c3;
    a[c1].l = c2;
    a[c1].r = c3;

    for (int i = 0; i < n - 1; ++i)
    {
        char c1;
        cin >> c1;
        cin >> a[c1].l >> a[c1].r;
    }
    print(c1);
    return 0;
}
