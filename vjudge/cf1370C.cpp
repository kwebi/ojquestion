#include <bits/stdc++.h>
using namespace std;
int a[2010];
typedef long long ll;

bool isPrime(int x)
{
    if (x == 2 || x == 3) {
        return 1;
    }
    if (x % 6 != 1 && x % 6 != 5) {
        return 0;
    }
    for (int i = 5; i * i <= x; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0) {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        if (n == 1) {
            printf("FastestFinger\n");
            continue;
        }
        if (n % 2 == 1 || n == 2) {
            printf("Ashishgup\n");
            continue;
        }
        if (n % 4 == 0) {
            n /= 4;
            while (n % 2 == 0) {
                n /= 2;
            }
            //cout << n << 'd' << endl;
            if (n == 1) {
                printf("FastestFinger\n");
                continue;
            } else {
                printf("Ashishgup\n");
                continue;
            }
        } else {
            while (n % 2 == 0) {
                n /= 2;
            }
            if (isPrime(n)) {
                printf("FastestFinger\n");
                continue;
            } else {
                printf("Ashishgup\n");
                continue;
            }
        }
    }

    return 0;
}