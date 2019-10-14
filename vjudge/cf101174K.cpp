#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct P {
    int x, y, z;
    bool operator<(const P& p) const
    {
        if (x == p.x)
            if (y == p.y)
                return z < p.z;
            else
                return y < p.y;
        else
            return x < p.x;
    }
};
map<P, int> mp1;
map<pii, int> mp2;

const int N = 1e6 + 7;

struct Union {
    int f[N];
    Union()
    {
        for (int i = 0; i < N; i++) {
            f[i] = i;
        }
    }
    int find(int x)
    {
        return x == f[x] ? x : f[x] = find(f[x]);
    }
    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x > y)
            swap(x, y);
        if (x != y)
            f[y] = x;
    }
    bool same(int x, int y)
    {
        x = find(x);
        y = find(y);
        return x == y;
    }
} U1, U2;

map<pii,int> edge1;
map<pii,int> edge2;

map<pii,int> vis;

int main()
{
    int k, x, y, z;
    scanf("%d", &k);
    int cnt = 0;
    int cnt1 = 0;
    for (int i = 1; i <= k; i++) {
        scanf("%d%d%d", &x, &y, &z);
        pii t1;
        P t;
        t = P{ x, y, z };
        t1 = pii(x, y);
        int d, d1;
        int rd,rd1;
        if (mp1.count(t) == 0)
            mp1[t] = ++cnt, d = cnt;
        else
            d = mp1[t];
        if (mp2.count(t1) == 0)
            mp2[t1] = ++cnt1,rd=cnt1;
        else rd=mp2[t1];
        scanf("%d%d%d", &x, &y, &z);
        t = P{ x, y, z };
        t1 = pii(x, y);
        if (mp1.count(t) == 0)
            mp1[t] = ++cnt, d1 = cnt;
        else
            d1 = mp1[t];
        if (mp2.count(t1) == 0)
            mp2[t1] = ++cnt1,rd1=cnt1;
        else rd1=mp2[t1];
        if (d != d1) {
            if (d > d1)
                swap(d, d1);
            edge1[pii(d, d1)]=1;
        }
        if(rd!=rd1){
            if(rd>rd1)swap(rd,rd1);
            edge2[pii(rd,rd1)]=1;
        }
    }
    bool f1=1;
    for(auto&e:edge1){
        int x=e.first.first;
        int y=e.first.second;
        if(U1.same(x,y)){
            f1=0;break;
        }else {
            U1.unite(x,y);
        }
    }
    bool f2=1;
    for(auto &e:edge2){
        int x=e.first.first;
        int y=e.first.second;
        if(U2.same(x,y)){
            f2=0;break;
        }else U2.unite(x,y);
    }
    if(!f1)printf("True closed chains\n");
    else printf("No true closed chains\n");
    if(!f2)printf("Floor closed chains\n");
    else printf("No floor closed chains\n");
    return 0;
}
