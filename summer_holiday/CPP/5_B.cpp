//
// Created by 弱冠 on 2018/7/19.
//
#include <cstdio>
int arr[2000];
int n;
int m;

int foo(int x) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (int)(arr[i] / x);
    }
    return sum;
}

int main() {
    while( scanf("%d %d", &n ,&m) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            arr[i] *= 100;
        }
        int max = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        int res = 0;
        int right = max;
        int left = 1;
        while (right >= left) {
            int mid = (right + left) >> 1;
            int cnt = foo(mid);
            if (cnt < m) {
                right = mid - 1;
            } else if (cnt == m) {
                res = res > mid ? res : mid;
                left = mid + 1;
            } else if (cnt > m) {
                res = res > mid ? res : mid;
                left = mid + 1;
            }
        }
        printf("%.2f\n", (double) (res / 100.0));
    }

    return 0;
}
