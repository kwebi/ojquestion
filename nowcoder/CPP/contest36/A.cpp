#include <stdio.h>
#include <iostream>
using namespace std;

char s[100000];
bool flag = false;

void compare(int j, int n)
{
    int k = j;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        if (j > n - k + n)
        {
            break;
        }
        else if (j >= n)
        {
            tmp = j - n;
        }
        else
        {
            tmp = j;
        }
        if (s[tmp] < s[i])
        {
            flag = true;
            break;
        }
        else if (s[tmp] > s[i])
        {
            break;
        }
        else
        {
            j++;
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;

    scanf("%d", &n);
    scanf("%s", s);

    for (int j = 1; j < n; j++)
    {
        compare(j, n);
    }
    if (flag)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
