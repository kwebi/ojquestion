//
// Created by 弱冠 on 2018/7/19.
//
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int n;
    int k;
    int arr[100];
    scanf("%d %d", &n, &k);
    for (int i =0;i< n;i++) {
        scanf("%d",&arr[i]);
    }
    long long count =0;
    sort(arr, arr+n);
    int right = n;
    int left = 0;
    int max_bei = (arr[n-2] + arr[n-1])/k;

    printf("%lld\n",count);
    return 0;
}
