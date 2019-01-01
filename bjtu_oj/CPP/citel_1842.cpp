#include<cstdio>
#include<iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    int i;
    for (i = 0; i < t; i++) {
        int n;
        cin >> n;
        int num[n];
        int j;
        for (j = 0; j < n; j++) {
            cin >> num[j];
        }
        long long sum = 0;
        for (j = 0; j < n; j++) {
            sum += num[j];
        }
        sum *= sum;
        long long tmp = 0;
        for (j = 0; j < n; j++) {
            tmp += num[j] * num[j];
        }
        sum = (sum + tmp) / 2;
        cout << sum << endl;
    }
    return 0;
}
