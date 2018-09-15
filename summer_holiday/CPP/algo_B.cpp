//
// Created by 弱冠 on 2018/7/17.
//
#include <cstdio>

int main() {
    int n;
    double gpa[101];
    for (int i = 0; i < 60; i++) {
        gpa[i] = 0;
    }
    for (int i = 60; i <=63; i++) {
        gpa[i] = 1.0;
    }
    for (int i = 64; i <=67;i++) {
        gpa[i] = 1.5;
    }
    for (int i = 68; i <=71;i++) {
        gpa[i] = 2.0;
    }
    for (int i = 72; i <=74;i++) {
        gpa[i] = 2.3;
    }
    for (int i = 75; i <=77;i++) {
        gpa[i] = 2.7;
    }
    for (int i = 78; i <=81;i++) {
        gpa[i] = 3.0;
    }
    for (int i = 82; i <=84;i++) {
        gpa[i] = 3.3;
    }
    for (int i = 85; i <=89;i++) {
        gpa[i] = 3.7;
    }
    for (int i = 90; i <=100;i++) {
        gpa[i] = 4.0;
    }
    while (scanf("%d",&n) == 1) {
        int a[10];
        double res = 0;
        int m = 0;
        int g[10];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i =0; i < n;i++) {
            m += a[i];
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &g[i]);
        }
        for (int i = 0; i < n;i++) {
            res += a[i]*gpa[g[i]];
        }
        printf("%.2lf\n", res/m);
    }
    return 0;
}
