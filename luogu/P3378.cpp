#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define LC(x) ((x)<<1)
#define RC(x) ((x)<<1|1)

const int N=2e6+5;
int heap[N];
int sz;
void push(int x){
    heap[++sz]=x;
    int now=sz;
    while(now){
        ll nxt=now>>1;
        if(heap[nxt]>heap[now])swap(heap[nxt],heap[now]);
        else break;
        now=nxt;
    }
}

void pop(){
    swap(heap[1],heap[sz]);
    sz--;
    int now=1;
    while(LC(now)<=sz){
        int nxt=LC(now);
        if(nxt+1<=sz&&heap[nxt+1]<heap[nxt])nxt++;
        if(heap[nxt]<heap[now])swap(heap[nxt],heap[now]);
        else break;
        now=nxt;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int t;
        scanf("%d",&t);
        if(t==1){
            int x;
            scanf("%d",&x);
            push(x);
        }else if(t==2){
            printf("%d\n",heap[1]);
        }else{
            pop();
        }
    }
    return 0;
}

