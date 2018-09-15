//
// Created by 弱冠 on 2018/7/17.
//

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 40
#define LL long long
using namespace std;
long long ans;
int n,s,a[N],b[N];
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int main()
{
    n=read();
    while(n)
    {
        a[++s]=n%2;
        n/=2;
    }
    if(s<32) a[++s]=0;s=0;
    for(int i=1;i<=32;i++)
        b[i]=a[32-i+1];
    for(int i=17;i<=32;i++)
        ans=ans*2+(LL)b[i];
    for(int i=1;i<=16;i++)
        ans=ans*2+(LL)b[i];
    printf("%lld",ans);
    return 0;
}