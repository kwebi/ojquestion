#include<iostream>
#include<stdio.h>
using namespace std;


int a[10];
int b[10];

void exgcd(int a,int b,int& x,int& y) {
    if(b==0) {
        x=1;
        y=0;
        return;
    }
    exgcd(b,a%b,x,y);
    int tp=x;
    x=y;
    y=tp-a/b*y;
}

int china(int k) {
    int ans=0,lcm=1,x,y;
    for(int i=1; i<=k; ++i)
        lcm*=b[i];
    for(int i=1; i<=k; ++i) {
        int tp=lcm/b[i];
        exgcd(tp,b[i],x,y);
        x=(x%b[i]+b[i])%b[i];
        ans=(ans+tp*x*a[i])%lcm;
    }
    return (ans+lcm)%lcm;
}

int main() {
    b[1]=23;
    b[2]=28;
    b[3]=33;
    int cnt=1;
    while(true) {
        int d;
        cin>>a[1]>>a[2]>>a[3]>>d;
        if(a[1]==-1)
            break;
        int x=china(3);
        int ans=x-d;
        if(ans<=0){
            ans+=21252;
        }
        printf("Case %d: the next triple peak occurs in %d days.\n",cnt++,ans);
    }
    return 0;
}
