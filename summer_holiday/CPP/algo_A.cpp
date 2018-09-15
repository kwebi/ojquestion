//
// Created by 弱冠 on 2018/7/17.
//
#include <cstdio>

int main() {
    int n = 0;
    int a[10];
    int l = 30;
    int ml;
    for (int i =0; i < 10; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &ml);
    for (int i = 0; i < 10; i++) {
        if (ml + l >= a[i]) {
            n++;
        }
    }
    printf("%d\n", n);
    return 0;
}
