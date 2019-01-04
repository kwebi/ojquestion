#include <stdio.h>
#include <iostream>
using namespace std;

char s[100000];
bool flag = false;

int main(int argc, char const *argv[])
{
    int n;

    scanf("%d", &n);
    scanf("%s", s);

    int len = 0;
    for (int j = 1; j < n && !flag; j++)
    {
        if (s[j] < s[len])
            flag = true;
        else if (s[j] == s[len])
            len++;
        else
            len = 0;
    }
    if (flag)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
