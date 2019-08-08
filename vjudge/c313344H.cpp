#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxn=1e4+5;
double a[maxn];
int n,k;

bool check(double x){
    int t=0;
    for(int i=1;i<=n;i++){
        t+=(int)(a[i]/x);
    }
    if(t>=k)return true;
    return false;
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lf",&a[i]);
    }
    double mend=1e9+7;
    double mst=0;
    for(int i=1;i<=100;i++){
        double mid=(mst+mend)/2;
        if(check(mid)){
            mst=mid;
        }else {
            mend=mid;
        }
    }
    printf("%.2lf",int(mend*100)/100.0);

    return 0;
}
