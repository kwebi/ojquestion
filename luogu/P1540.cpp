#include<stdio.h>
#include<deque>
#include<algorithm>
using namespace std;

const int N=2e5;
int a[N];

int main(){
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	int res=0;
	deque<int> cache;
	for(int i=0;i<n;++i)
	{
		if(cache.size()<=m-1)
		{
			auto it=find(cache.begin(),cache.end(),a[i]);
			if(it==cache.end()){
				cache.push_back(a[i]);
				++res;
			}
		}
		else{
			auto it=find(cache.begin(),cache.end(),a[i]);
			if(it==cache.end())
			{
				cache.pop_front();
				cache.push_back(a[i]);
				++res;
			}
			
		}
	}
	printf("%d\n",res);
	return 0;
}