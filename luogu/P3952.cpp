#include<string>
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
string a,b;     //a,b循环使用 
int c,d,e,f[27],g[27],h,k,l[100],m,n,o;
//c是有几个句子，d是题目给的复杂度是多少
//e是当前在几重循环，f[]是判断变量是否使用过
//g[]是存下每个循环的变量，h是当前复杂度是多少(与e不同)
//k是判断下面程序是否进行，l[]是存下哪几个循环加了复杂度
//m是当前最大复杂度，n是存下k=1时的循环数
//o是数据组数 
int main()
{
    cin>>o;    //读入数据组数 
    while(o>0)
    {
        c=0;d=0;m=0;n=0;e=0;h=0;k=0;o--;      //初始化，剩余数据组数-1 
        memset(f,0,sizeof(f));memset(l,0,sizeof(l));   //初始化 
        do{a=b;cin>>b;} while(b[0]!='O');     //读入，当b[0]='O'时停下，保证ERR时下一个继续运行 
        for(int i=0;i<a.length();i++) c=c*10+a[i]-'0';   //取出题目给的句子数量 
        for(int i=4;i<b.length()-1;i++) d=d*10+b[i]-'0';  //取出题目给的时间复杂度 O(1)不影响 
        while(c>0)
        {
            c--;cin>>a;   //读入F 或 E ,句子数-1
            if(a[0]=='F')   //如果是F 
            {
                e++;cin>>a;   //当前循环数+1，读入变量 
                if(f[a[0]-96]) e=-1;    //如果被用过，标记ERR 
                else f[a[0]-96]=1,g[e]=a[0]-96;    //没用过就标记用过，并存起来 
                cin>>a>>b;      //读入变量初值和末值 
                if(a[0]!='n'&&b[0]=='n'&&k==0) h++,l[e]=1;   //如果a是数字，b是n，而且可以运行，那么当前复杂度+1，记下循环数 
                else if(((a.length()==b.length()&&a>b)||(a.length()>b.length())||(a[0]=='n'&&b[0]!='n'))&&k==0) k=1,n=e;
                //如果a>b(n 4,45 12,24 9),而且可以运行，那么标记下面的都不能运行，记下当前循环 
                //像5 8，76 78, n n 之类的不影响，不需要处理 
            }else
            {      //如果是E 
                m=max(m,h);f[g[e]]=0;     //将最大复杂度更改 ，变量标记没用过 
                if(l[e]==1) h--,l[e]=0;    //如果当前循环加了复杂度，当前复杂度-1，标记清空 
                e--;    //当前循环数-1 
                if(n>0&&e<n) k=0,n=0;   //如果跳出了n标记的那个循环，那么接下来的循环可以运行，标记清空 
            }
            if(e==-1) printf("ERR\n"),c=-1;   //如果e<0(变量用过或者E过多)，那么输出ERR，跳出循环 
        }
        if(e>0) printf("ERR\n");    //如果e>0(F过量)，那么输出ERR，跳出循环 
        if(e==0&&m==d) printf("Yes\n");   //如果F,E相同而且最大复杂度等于题目给的复杂度，输出Yes 
        if(e==0&&m!=d) printf("No\n");    //如果F,E相同而且最大复杂度不等于题目给的复杂度，输出No 
    }
    return 0;
}
