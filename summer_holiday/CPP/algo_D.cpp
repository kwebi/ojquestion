//
// Created by 弱冠 on 2018/7/17.
//
#include <cstdio>
#include <cmath>
int main() {
    long long a;
    long long b;
    scanf("%lld %lld",&a,&b);
    unsigned long long res ;
    if (a > b) {
        res = a-b;
    } else {
        res = b -a;
    }
    unsigned long long n = res;
    char array[1000];
    int i=0;
    int j=0;
    int t=0;
    unsigned long long tmp = n;
    while (tmp > 0) {
        tmp /= 10;
        t++;
    }
    while (n>0) {
        array[i++]=(char)(n%10+(int)('0'));
        n /= 10;
        j++;
        if (j %3 == 0 && j < t) {
            array[i]= ',';
            i++;
        }
        array[i]='\0';
    }
    if (a-b < 0) {
        array[i] ='-';
        array[i+1]='\0';
        i++;
    }
    for ( j= i-1;j>=0;j--){
        printf("%c",array[j]);
    }
    printf("\n");
    return 0;
}
