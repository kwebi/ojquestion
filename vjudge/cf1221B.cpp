#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define LC(x) ((x)<<1)
#define RC(x) ((x)<<1|1)


int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if((i+j)&1){
                printf("B");
            }else printf("W");
        }
        printf("\n");
    }
    return 0;
}


