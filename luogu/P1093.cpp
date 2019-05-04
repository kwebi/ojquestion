#include <algorithm>
#include <cstdio>

using namespace std;

struct Stu
{
    int a;
    int b;
    int c;
    int num;
    int sum;
};

int main()
{
    int n;
    scanf("%d", &n);
    Stu s[305];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d%d", &s[i].a, &s[i].b, &s[i].c);
        s[i].num = i + 1;
        s[i].sum = s[i].a + s[i].b + s[i].c;
    }

    sort(s, s + n, [](Stu &a, Stu &b) -> bool {
        if (a.sum == b.sum)
        {
            if (a.a == b.a)
            {
                return a.num < b.num;
            }
            return a.a > b.a;
        }
        return a.sum > b.sum;
    });

    for(int i=0;i<5;i++)
    {
        printf("%d %d\n",s[i].num,s[i].sum);
    }

    return 0;
}