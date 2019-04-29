#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int num[10];
    char str[15];
    int j = 0;
    for (int i = 0; i < s.size() - 1; ++i)
    {
        str[i] = s[i];
        if (s[i] != '-')
        {
            num[j] = s[i] - '0';
            ++j;
        }
    }
    int sum = 0;
    for (int i = 0; i < 9; ++i)
    {
        sum += ((i + 1) * num[i]) % 11;
    }
    int res = sum % 11;

    if (res == 10)
    {
        if (s[12] == 'X')
            printf("Right");
        else
        {
            str[12] = 'X';
            printf("%s", str);
        }
    }
    else
    {
        if ((s[12] - '0') == res)
        {
            printf("Right");
        }
        else
        {
            str[12] = res + '0';
            printf("%s", str);
        }
    }
    return 0;
}
