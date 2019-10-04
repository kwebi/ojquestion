//kwb 2019.9.23
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int N=2e5+5;
char s[N];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    if(m==0){
        printf("%s",s);return 0;
    }
    if(n==1){    
        printf("0\n");
        return 0;
    }
    int cnt=0;
    int len=strlen(s);
    for(int i=0;i<len;i++){
        if(i==0&&s[i]>'1'){
            cnt++;
            if(cnt<=m){
                printf("1");
            }else printf("%c",s[i]);
        }
        else if(i!=0&&s[i]>'0'){
            cnt++;
            if(cnt<=m){
                printf("0");
            }else printf("%c",s[i]);
        }
        else printf("%c",s[i]);
    }
    return 0;
}

