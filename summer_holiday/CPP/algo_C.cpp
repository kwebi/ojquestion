//
// Created by 弱冠 on 2018/7/17.
//
#include <cstdio>
#include <cmath>
int main() {
    long long num;
    scanf("%lld",&num);
    long long x  =num;
    int i;
    int tmp[32];
    for ( i=0; x>0;) {
        tmp[i++] = (int)(x%2);
        x /= 2;
    }
    int t=0;
    for (int j=i;j<32;j++) {
        tmp[j]=0;
    }
    for (int j=0,j1=16;j<16;j++,j1++) {
        int tmp1 =tmp[j];
        tmp[j]=tmp[j1];
        tmp[j1]=tmp1;
    }
    long long res=0;
    for (int j=0;j<32;j++) {
        res += tmp[j]*pow(2,j);
    }
    printf("%lld\n",res);
    return 0;
}
