//http://citel.bjtu.edu.cn/vjudge/contest/view.action?cid=330#overview
#include<stdio.h>
#include<algorithm>
using namespace std;

const int MAXN=1e5+5;

int a[MAXN];
int b[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    long long sum=0;
    for(int i=0;i<n;++i)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    for(int i=0;i<n;++i)
        scanf("%d",&b[i]);
    sort(b,b+n);
    long long cap=b[n-2]+b[n-1];
    if(sum>cap)
        puts("NO");
    else
        puts("YES");
    return 0;
}
