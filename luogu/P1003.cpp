#include<stdio.h>

const int N=100005;
int a[N];
int b[N];
int g[N];
int k[N];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d %d %d %d",&a[i],&b[i],&g[i],&k[i]);
    }
    int x,y;
    scanf("%d%d",&x,&y);
    int flag=-1;
    for(int i=n-1;i>=0;--i)
    {
        if(x>=a[i]&&y>=b[i]&&x<=a[i]+g[i]&&y<=b[i]+k[i])
        {
            flag=i+1;
            break;
        }
    }
    printf("%d\n",flag);
    return 0;
}
