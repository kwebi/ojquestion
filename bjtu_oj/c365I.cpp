#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e5+5;
const int INF=2e9+7;

struct Treap {
	int ch[maxn][2];//结点左右儿子
	int val[maxn],dat[maxn];//基本值和优先级
	int size[maxn],cnt[maxn];//子树大小，结点副本数
	int tot,root;
	int New(int v) {
		val[++tot]=v;
		dat[tot]=rand();//随机优先级
		size[tot]=1;
		cnt[tot]=1;
		return tot;
	}
	void pushup(int id) {
		size[id]=size[ch[id][0]]+size[ch[id][1]]+cnt[id];
	}
	void build() {
		root=New(-INF),ch[root][1]=New(INF);
		pushup(root);
	}
	void rotate(int& id,int d) { //id是引用传递，d(irection)为旋转方向，0为左旋，1为右旋
		int temp=ch[id][d^1];
		ch[id][d^1]=ch[temp][d];
		ch[temp][d]=id;
		id=temp;
		pushup(ch[id][d]),pushup(id);
	}
	void insert(int& id,int v) {
		if(!id) {
			id=New(v);
			return;
		}
		if(v==val[id])cnt[id]++;
		else {
			int d=v<val[id]?0:1;
			insert(ch[id][d],v);
			if(dat[id]<dat[ch[id][d]])rotate(id,d^1);
		}
		pushup(id);
	}
	void remove(int&id,int v) {
		if(!id)return;
		if(v==val[id]) {
			if(cnt[id]>1) {
				cnt[id]--,pushup(id);
				return;
			}
			if(ch[id][0]||ch[id][1]) {
				if(!ch[id][1]||dat[ch[id][0]]>dat[ch[id][1]]) {
					rotate(id,1),remove(ch[id][1],v);
				} else {
					rotate(id,0),remove(ch[id][0],v);
				}
				pushup(id);
			} else id=0;
			return;
		}
		v<val[id]?remove(ch[id][0],v):remove(ch[id][1],v);
		pushup(id);
	}
	int getRank(int id,int v) {
		if(!id)return 0;
		if(v==val[id])return size[ch[id][0]]+1;
		else if(v<val[id])return getRank(ch[id][0],v);
		else return size[ch[id][0]]+cnt[id]+getRank(ch[id][1],v);
	}
	int getVal(int id,int rank) {
		if(!id)return INF;
		if(rank<=size[ch[id][0]])return getVal(ch[id][0],rank);
		else if(rank<=size[ch[id][0]]+cnt[id])return val[id];
		else return getVal(ch[id][1],rank-size[ch[id][0]]-cnt[id]);
	}
	int getPre(int v) {
		int id=root,pre;
		while(id) {
			if(val[id]<v)pre=val[id],id=ch[id][1];
			else id=ch[id][0];
		}
		return pre;
	}
	int getNext(int v) {
		int id = root,next;
		while(id) {
			if(val[id] > v)next = val[id],id = ch[id][0];
			else id = ch[id][1];
		}
		return next;
	}
} trp;

int main() {
	trp.build();
	int n;
	scanf("%d",&n);
	while(n--){
		int opt,x;
		scanf("%d%d",&opt,&x);
		int ans=-INF;
		int& r=trp.root;
		switch(opt){
			case 1:{
				trp.insert(r,x);
				break;
			}
			case 2:{
				trp.remove(r,x);
				break;
			}
			case 3:{
				ans= trp.getRank(r,x)-1;
				break;
			}
			case 4:{
				ans=trp.getVal(r,x+1);
				break;
			}
			case 5:{
				ans=trp.getPre(x);
				break;
			}
			case 6:{
				ans=trp.getNext(x);
				break;
			}
		}
		if(ans!=-INF)
		printf("%d\n",ans);
	}
	return 0;
}
