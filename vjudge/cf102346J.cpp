#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

char s[11];
const int N = 110;

struct Node {
    map<int, int> val;
    bool w = false;
    int cnt = 0;
    int win()
    {
        if (w || val.size() != 1) {
            return 0;
        }
        for (auto& e : val) {
            if (e.second == 4) {
                return e.first;
            }
        }
        return 0;
    }
};

Node a[N];
int n, k;

int getN(int now)
{
    if (now + 1 > n) {
        return 1;
    }
    return now + 1;
}

void change(int now, int nx)
{
    int cmi = 100;
    int mi = 100;
    unordered_map<int, int> rmp;
    for (auto e : a[now].val) {
        rmp[e.first] = e.second;
    }
    for (auto e : rmp) {
        if (e.second < mi) {
            mi = e.second;
            cmi = e.first;
        } else if (e.second == mi) {
            if (e.first < cmi) {
                cmi = e.first;
            }
        }
    }
    a[now].val[cmi]--;
    if (a[now].val[cmi] == 0) {
        a[now].val.erase(cmi);
    }
    a[nx].val[cmi]++;
}

void pf(int now)
{
    printf("%d %d\n", now, a[now].w);
    for (auto e : a[now].val) {
        printf("%d %d\n", e.first, e.second);
    }
}

int winner(){
    int wi=0,wx=100;
    for(int i=1;i<=n;i++){
        int t=a[i].win();
        if(t>0){
            if(wi>0){
                if(wx>t){
                    wi=i;
                    wx=t;
                }
            }else{
                wi=i,wx=t;
            } 
        }
    }
    return wi;
}

int main()
{
    scanf("%d%d", &n, &k);
    a[k].w = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        int len = strlen(s);
        for (int j = 0; j < len; j++) {
            int val;
            if (s[j] == 'A') {
                val = 1;
            } else if (s[j] == 'D') {
                val = 10;
            } else if (s[j] == 'Q') {
                val = 11;
            } else if (s[j] == 'J') {
                val = 12;
            } else if (s[j] == 'K') {
                val = 13;
            } else
                val = s[j] - '0';
            a[i].val[val] += 1;
        }
    }
    int now = k;
    while (true) {
        int flag=winner();
        if(flag){
            printf("%d\n",flag);
            return 0;
        }
        int nx = getN(now);
        if (a[now].w) {
            if (a[now].cnt == 0) {
                a[now].cnt++;
                change(now, nx);
            } else {
                a[now].cnt = 0;
                a[now].w = 0;
                a[nx].w = 1;
            }
        } else {
            change(now, nx);
        }
        
        now = nx;
    }
    return 0;
}
