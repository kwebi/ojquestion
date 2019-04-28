#include<algorithm>
#include<stdio.h>

using namespace std;

int a[30005];

int main()
{
    int w;
    int n;
    scanf("%d",&w);
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int i=0;
    int j=n-1;
    int ans = 0;
    while(i<j)
    {
        if(a[i]+a[j]>w)
        {
            ++ans;
            --j;
        }
        else
        {
            ++ans;
            ++i;
            --j;
        }
    }
    if(i==j)
        ++ans;
    printf("%d\n",ans);
    return 0;
}
