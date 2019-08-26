#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int N=1e6+5;
char s[N];
int yin[N];
/*Solution 1
int main() {
	while(~scanf("%s",s)) {
		if(s[0]=='.')break;
		int len=strlen(s);
		int cnt=0;
		for(int i=1; i*i<=len; i++) {
			if(len%i==0) {
				yin[cnt++]=i;
				yin[cnt++]=len/i;
			}
		}
		sort(yin,yin+cnt);
		for(int j=0; j<cnt; j++) {
			bool f=1;
			for(int i=yin[j]; i<len; i++) {
				if(s[i]!=s[i-yin[j]]){
					f=0;break;
				}
			}
			if(f){
				printf("%d\n",len/yin[j]);
				break;
			}
		}
	}
	return 0;
}
*/

//Solution 2

void kmp_pre(char x[],int m,int next[]){
	int i,j;
	j=next[0]=-1;
	i=0;
	while(i<m){
		while(j!=-1&&x[i]!=x[j])j=next[j];
		next[++i]=++j;
	}
}

int main()
{
	while(~scanf("%s",s)) {
		if(s[0]=='.')break;
		int len=strlen(s);
		kmp_pre(s,len,yin);
		int t=len-yin[len];
		if(len%t==0)printf("%d\n",len/t);
		else printf("1\n");
	}
	return 0;
}
