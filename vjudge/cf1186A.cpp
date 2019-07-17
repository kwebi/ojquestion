#include<stdio.h>

int main() {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    if(m>=n&&k>=n)
        printf("YES\n");
    else 
        printf("NO\n");
    return 0;
}

