#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n,k;
        scanf("%d%d",&n,&k);
        if(k%3!=0) {
            if(n%3==0) {
                printf("Bob\n");
            } else {
                printf("Alice\n");
            }
        } else {
            int n1 = n%(k+1);
            if(n1!=k&&n1%3==0) {
                printf("Bob\n");
            }else {
                printf("Alice\n");
            }
        }
    }
    return 0;
}
