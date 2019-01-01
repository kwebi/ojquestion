//
// Created by 弱冠 on 2018/7/19.
//
#include <cmath>
#include <cstdio>
typedef struct node {
    int x0;
    int y0;
}Node;

Node is_max_min(int P, int Q) {
    int m = P;
    int n = Q;
    while (m != n) {
        if (m > n) {
            m = m -n;
        } else if (n > m) {
            n = n - m;
        }
    }
    Node node1;
    node1.x0 = m;
    node1.y0 = P * Q /m;
    return node1;
}

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    int sqrt_xy = (int)sqrt(x*y);
    int count = 0;
    int n = 0;
    int i = x * y;
    while (i >= sqrt_xy) {
        int j = sqrt_xy;
        while (j > 0) {
            if (i * j == x * y) {
                Node node1 = is_max_min(i, j);
                if (node1.x0 == x && node1.y0 == y) {
                    if (i == sqrt_xy && j == sqrt_xy) {
                        n = 1;
                    }
                    count++;
                }
            }
            j -= 1;
        }
        i -= 1;
    }
    if (n) {
        printf("%d\n", count*2 -1);
    } else {
        printf("%d\n", count*2);
    }
    return 0;
}