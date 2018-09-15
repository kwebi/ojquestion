//
// Created by 弱冠 on 2018/7/18.
//

#include <queue>
#include <cstdlib>
#include <cstdio>
using namespace std;
int main() {
    queue<int> q;
    int n;
    int array[100000];
    scanf("%d", &n);
    for (int i = 0; i< n; i++) {
        scanf("%d", &array[i]);
    }
    int new_arr[100000];
    for (int i = 0; i< n; i++) {
        new_arr[array[i]-1] = i;
    }

    return 0;
}