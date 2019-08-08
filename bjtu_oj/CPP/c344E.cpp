#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stack>
#include<algorithm>
using namespace std;

int f[110][110];
char s[110];

bool check(char s1,char s2){
    return (s1=='('&&s2==')')||(s1=='['&&s2==']');
}

int main() {
	while(true) {
		memset(f,0,sizeof(f));
		scanf("%s",s+1);
		if(s[1]=='e')break;

		int n=strlen(s+1);
		//printf("%d\n",check(s[1],s[2]));
		for(int i=1; i<=n; i++) {
			for(int j=1; j+i<=n; j++) {
			    int e=i+j;
			    if(check(s[j],s[e])){
			        f[j][e]=f[j+1][e-1]+2;
                }
                for(int k=j;k<e;k++){
                    f[j][e]=max(f[j][e],f[j][k]+f[k+1][e]);
                }
                //printf("%d %d %d\n",j,e,f[j][e]);
			}
		}

		printf("%d\n",f[1][n]);
	}
	return 0;
}

