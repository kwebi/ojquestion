//
// Created by 弱冠 on 2018/7/19.
//
#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> stk;
int arr[50];

int n;
int v;

void combine(int sum, int&x, int&count) {
    if (stk.size() == n+1) {
        return;
    } else if (stk.size() == 1) {
        x += 1;
    }
    int i;
    for ( i=x; i < n; ) {
        if (find(stk.begin(),stk.end(),arr[i]) != stk.end()) {
            i++;
        }
        else {
            if (sum + arr[i] <= v) {
                count++;
                stk.push_back(arr[i]);
                combine(sum+arr[i], x,count);
                stk.pop_back();
            }
            i++;
        }
    }
    if (i >= n) {
        return;
    }
}

int main() {
    scanf("%d %d", &n, &v);
    for (int i = 0; i<n;i++) {
        scanf("%d", &arr[i]);
    }
    int x = 0;
    int count = 0;
    combine(0, x,count);
    printf("%d\n",count+1);
    return 0;
}
