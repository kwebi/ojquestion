#include<bits/stdc++.h>
using namespace std;
struct node {
    int v;
    int i;
};

node a[105];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	queue<node> Q;
	for(int i=1;i<=n;i++){
        scanf("%d",&a[i].v);
        a[i].i=i;
        Q.push(a[i]);
	}

	while(Q.size()!=1){
        node fmt=Q.front();
        Q.pop();
        if(fmt.v>m){
            fmt.v-=m;
            Q.push(fmt);
        }
	}
	node ans=Q.front();
	printf("%d",ans.i);

	return 0;
}
