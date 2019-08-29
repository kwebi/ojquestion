#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
char s[N];

int main()
{
    gets(s);
    int len = strlen(s);
    string ans;
    for (int i = 0; i < len;i++) {
        if(s[i]!=' '){
            ans.push_back(s[i]);
        }
    }
    for(int i=0;i<ans.size();i++){
        if(i==ans.size()-1)printf("%c",ans[i]);
        else printf("%c ",ans[i]);
    }
    return 0;
}