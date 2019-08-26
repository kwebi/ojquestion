//
// Created by 弱冠 on 2018/7/8.
//
#include <cstdio>

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int n;
        scanf("%d", &n);
        if ((n % 3) == 0 || (n % 2) == 0) {
            printf("Y\n");
        }

    }
    return 0;
}
