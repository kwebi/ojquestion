#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int Has1[55];
int Has2[55];

int main(){
    int n,d,c;
    scanf("%d%d%d",&n,&d,&c);
    for(int i=1;i<=c;i++){
        int t;
        scanf("%d",&t);
        Has1[t]=1;
    }
    for(int i=1;i<=c;i++){
        int t;
        scanf("%d",&t);
        Has2[t]=1;
    }
    
    return 0;
}

