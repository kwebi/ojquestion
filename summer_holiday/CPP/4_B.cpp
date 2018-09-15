//
// Created by 弱冠 on 2018/7/18.
//
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    int n;
    scanf("%d", &n);
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    for (int i = 1; i <= n; i++) {
        int q_size = q.size();
        int e_head1 = q.front();
        q.pop();
        int e_head2;
        if (q_size != 1) {
            e_head2 = q.front();
            q.pop();
        }
        int point = e_head1 % i;
        res += point;
        if (q_size != 1) {
            q.push(e_head2);
        }
    }
    printf("%lld\n", res);
    return 0;
}
