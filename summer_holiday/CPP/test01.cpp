//
// Created by 弱冠 on 2018/7/2.
//
#include <cstdio>

int main() {
    int a[100];
    for (int i = 0; i < 100; i++) {
        a[i] = i;
    }

    for (int i = 0; i < 100; i++) {
        printf("%d", a[i]);
    }
    return 0;
}

