#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    char s[100];
    char fs[100];
    scanf("%s", s);
    int len = strlen(s);
    int pos = len;
    for (int i = 0; i < len; ++i)
    {
        if (s[i] == '.' || s[i] == '/' || s[i] == '%')
        {
            pos = i;
            break;
        }
        fs[i] = s[i];
    }
    int beg = 0;
    int end;
    if (pos != len)
        end = pos - 1;
    else
    {
        end = len - 1;
    }

    while (beg <= end)
    {
        swap(fs[beg], fs[end]);
        ++beg;
        --end;
    }
    beg = pos + 1;
    end = len - 1;
    while (beg <= end)
    {
        swap(s[beg], s[end]);
        ++beg;
        --end;
    }
    int i = 0;
    while (i < pos && fs[i] == '0')
        ++i;
    for (int j = i; j < pos; ++j)
        printf("%c", fs[j]);

    if (i == pos)
        printf("0");
    if (pos != len)
    {
        printf("%c", s[pos]);

        if (s[pos] == '.')
        {
            i = len - 1;
            while (i > pos && s[i] == '0')
                --i;
            for (int j = pos + 1; j <= i; ++j)
                printf("%c", s[j]);
            if (i == pos)
            {
                printf("0");
            }
        }
        else if (s[pos] == '/')
        {
            i = pos + 1;
            while (i < len && s[i] == '0')
                ++i;
            for (int j = i; j < len; ++j)
                printf("%c", s[j]);
        }
    }
    return 0;
}
