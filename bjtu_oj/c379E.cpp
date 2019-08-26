#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int N=1e5+5;
char s[N];
int Next[N];

void kmp_pre(char x[],int m,int next[]){
	int i,j;
	j=next[0]=-1;
	i=0;
	while(i<m){
		while(j!=-1&&x[i]!=x[j])j=next[j];
		next[++i]=++j;
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		int len=strlen(s);
		kmp_pre(s,len,Next);
		int l=len-Next[len];
		if(len%l==0&&l!=len)printf("0\n");
		else printf("%d\n",l-Next[len]%l);
	}
	return 0;
}


