#include<stdio.h>

const int maxn=1e3+5;

double x[maxn];
double y[maxn];


int main() {
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;++t) {
        int n;
        double r;
        scanf("%d%lf",&n,&r);
        for(int i=0;i<n;++i)
            scanf("%d%d",&x[i],&y[i]);
        
    }
}