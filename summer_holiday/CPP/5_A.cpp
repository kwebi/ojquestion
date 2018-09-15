//
// Created by 弱冠 on 2018/7/19.
//
#include <cstdio>

#include<time.h>
int is_prime(int n){
    int i;
    if (n <= 1) {
        return 0;
    }
    if (n==2) {
        return 1;
    }
    for (i = 2;i < n;i++) {
        if(n%i==0) return 0;
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    if (!is_prime(n)) {
        printf("No\n");
        return 0;
    }
    int arr[1000];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (is_prime(i)) {
            arr[j] = i;
            j++;
        }
    }
    int is = 0;
    for (int i = 2; i < j-1; i++) {
        for (int k = 1; k < i; k++) {
            for (int m = 0; m < k; m++) {
                if (arr[i] + arr[k] +arr[m] == n) {
                    is = 1;
                    break;
                }
            }
            if (is) {
                break;
            }
        }
        if(is) {
            break;
        }
    }
    if (is) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }
    return 0;
}
