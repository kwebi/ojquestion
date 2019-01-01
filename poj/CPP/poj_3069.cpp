#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int R;
int n;
int a[1005];

int main() {
    while(1) {
        cin >> R >> n;
        if (R == -1 && n == -1) {
            break;
        }
        int i;
        int j;
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        i = 0;
        int res = 0;
        sort(a, a+n);
        while (i < n) {
            int s = a[i++];
            while (i < n && a[i] <= s + R) i++;
            int p = a[i - 1];
            while (i < n && a[i] <= p + R) i++;
            res++;
        }
        printf("%d\n", res);
    }
    return 0;
}