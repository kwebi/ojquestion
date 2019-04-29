#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int judge(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    if (c >= 'A' && c <= 'Z')
        return 2;
    if (c >= 'a' && c <= 'z')
        return 3;
}

int main()
{
    int p1, p2, p3;
    scanf("%d%d%d", &p1, &p2, &p3);
    string s;
    string ans;
    cin >> s;
    if (s.size() > 0)
        printf("%c", s[0]);
    for (int i = 1; i < s.size() - 1; ++i)
    {
        if (s[i] == '-' && s[i + 1] > s[i - 1])
        {
            char beg = s[i - 1];
            char end = s[i + 1];
            int t = judge(s[i - 1]);
            int t2 = judge(s[i + 1]);
            if (!(t == 1 && t2 == 1 || t == 2 && t2 == 2 || t == 3 && t2 == 3))
            {
                printf("%c", s[i]);
                continue;
            }
            if (t == 2 && p1 == 1)
            {
                beg += 'a' - 'A';
                end += 'a' - 'A';
            }
            if (t == 3 && p1 == 2)
            {
                beg -= 'a' - 'A';
                end -= 'a' - 'A';
            }
            if (p3 == 2)
            {
                for (char c = end - 1; c > beg; c--)
                {
                    for (int j = 1; j <= p2; ++j)
                    {
                        if (p1 == 3)
                            printf("*");
                        else
                            printf("%c", c);
                    }
                }
            }
            else if (p3 == 1)
            {
                for (char c = beg + 1; c < end; c++)
                {
                    for (int j = 1; j <= p2; ++j)
                    {

                        if (p1 == 3)
                            printf("*");
                        else
                            printf("%c", c);
                    }
                }
            }
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("%c", s[s.size() - 1]);
    return 0;
}
