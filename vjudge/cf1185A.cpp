#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;

int main() {
    int a[3],d;
    scanf("%d%d%d%d",&a[0],&a[1],&a[2],&d);
    sort(a,a+3);
    int d1=a[1]-a[0];
    int d2=a[2]-a[1];
    long long ans=0;
    if(d1<d)
        ans+=(d-d1);
    if(d2<d)
        ans+=(d-d2);
    cout << ans <<endl;

    return 0;
}
