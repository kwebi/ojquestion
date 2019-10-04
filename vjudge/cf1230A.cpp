//kwb 2019.9.23
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define LC(x) ((x)<<1)
#define RC(x) ((x)<<1|1)

int a[10];

int main(){
    int s=0;
    for(int i=0;i<4;i++){
        scanf("%d",&a[i]);
        s+=a[i];
    }
    for(int i=0;i<(1<<3);i++){
        int ans=0;
        for(int j=0;j<4;j++){
            if(i&(1<<j)){
                ans+=a[j];
            }
        }
        if(ans==s-ans){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}

