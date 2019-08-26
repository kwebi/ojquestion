#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

const int N=5e5+5;
int a[30];
char s[N];
char rs[N];
int Next[N];
int Extend1[N];
int Extend2[N];
int sum[N];

void pre_ekmp(char x[],int m,int next[]) {
	next[0]=m;
	int j=0;
	while(j+1<m&&x[j]==x[j+1])j++;
	next[1]=j;
	int k=1;
	for(int i=2; i<m; i++) {
		int p=next[k]+k-1;
		int L=next[i-k];
		if(i+L<p+1)next[i]=L;
		else {
			j=max(0,p-i+1);
			while(i+j<m&&x[i+j]==x[j])j++;
			next[i]=j;
			k=i;
		}
	}
}

void ekmp(char x[],char y[],int m,int n,int next[],int extend[]) {
	pre_ekmp(x,m,next);
	int j=0;
	while(j<m&&j<n&&x[j]==y[j])j++;
	extend[0]=j;
	int k=0;
	for(int i=1; i<n; i++) {
		int p=extend[k]+k-1;
		int L=next[i-k];
		if(i+L<p+1)extend[i]=L;
		else {
			j=max(0,p-i+1);
			while(i+j<n&&y[i+j]==x[j])j++;
			extend[i]=j;
			k=i;
		}
	}
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		memset(Extend1,0,sizeof(Extend1));
		memset(Extend2,0,sizeof(Extend2));
		for(int i=0; i<26; i++) {
			scanf("%d",&a[i]);
		}
		scanf("%s",s);
		int len=strlen(s);
		for(int i=0; i<len; i++) {
			if(i==0)sum[i]=a[s[i]-'a'];
			else sum[i]=sum[i-1]+a[s[i]-'a'];
			rs[i]=s[len-i-1];
		}
		memset(Next,0,sizeof(Next));
		ekmp(s,rs,len,len,Next,Extend1);
		memset(Next,0,sizeof(Next));
		ekmp(rs,s,len,len,Next,Extend2);
		int ans=-1e9;
		
		for(int i=1;i<len;i++){
			int tmp=0;
			if(Extend1[i]+i-1==len-1){
				tmp+=sum[len-1-i];
			}
			int t=len-i;
			if(Extend2[t]+t-1==len-1){
				tmp+=sum[len-1]-sum[t-1];
			}
			ans=max(ans,tmp);
		}
		printf("%d\n",ans);
	}
	return 0;
}


