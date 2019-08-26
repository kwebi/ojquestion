#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int a[2010];

int main(){
	int k;
	scanf("%d",&k);
	a[0]=-1;
	int ans=1;
	for(int i=2;i<=2000;i++){
		int tmp=(k+i)/(i-1);
		int t1=k+i-tmp*(i-1)+tmp;
		if(tmp<=int(1e6)&&tmp>=1&&t1<=int(1e6)){
			ans=i;break;
		}
	}
	int sum=k+ans;
	int t=sum/(ans-1);
	int t1=sum-t*(ans-1);
	printf("%d\n",ans);
	printf("-1 ");
	for(int i=1;i<=ans-1;i++){
		if(i==ans-1){
			printf("%d\n",t+t1);
		}else {
			printf("%d ",t);
		}
	}
	return 0;
}
