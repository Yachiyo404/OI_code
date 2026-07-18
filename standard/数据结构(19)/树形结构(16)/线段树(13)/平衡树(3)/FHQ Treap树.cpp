#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e6+5;
struct cxt{int ls,rs,val,pri,sz;}t[N];
int rt,cnt;
void init(int x)//初始化
{
	cnt++;
	t[cnt].sz=1;
	t[cnt].ls=0;
	t[cnt].rs=0;
	t[cnt].val=x;
	t[cnt].pri=rand();
	return ;
}
void upd(int x){t[x].sz=t[t[x].ls].sz+t[t[x].rs].sz+1;return ;}
void sp(int u,int x,int &L,int &R)//分裂
{
	if(u==0){L=0;R=0;return ;}
	if(t[u].val<=x){L=u;sp(t[u].rs,x,t[u].rs,R);}
	else{R=u;sp(t[u].ls,x,L,t[u].ls);}
	upd(u);
	return ;
}
int mg(int L,int R)//合并
{
	if(L==0||R==0){return L+R;}
	if(t[L].pri>t[R].pri){t[L].rs=mg(t[L].rs,R);upd(L);return L;}
	else{t[R].ls=mg(L,t[R].ls);upd(R);return R;}
}
void insert(int x)//插入
{
	int L,R;
	sp(rt,x,L,R);
	init(x);
	rt=mg(mg(L,cnt),R);
	return ;
}
void del(int x)//删除
{
	int L,R,p;
	sp(rt,x,L,R);
	sp(L,x-1,L,p);
	p=mg(t[p].ls,t[p].rs);
	rt=mg(mg(L,p),R);
	return ;
}
void rnk(int x)//排名
{
	int L,R;
	sp(rt,x-1,L,R);
	cout<<t[L].sz+1<<'\n';
	rt=mg(L,R);
	return ;
}
int kth(int u,int k)//在以u为根的子树中找排名为k的数
{
	if(k==t[t[u].ls].sz+1)return u;//返回编号
	if(k<=t[t[u].ls].sz)return kth(t[u].ls,k);
	if(k>t[t[u].ls].sz)return kth(t[u].rs,k-t[t[u].ls].sz-1);
}
void pre(int x)//前驱
{
	int L,R;
	sp(rt,x-1,L,R);
	cout<<t[kth(L,t[L].sz)].val<<'\n';
	rt=mg(L,R);
	return ;
}
void nxt(int x)//后继
{
	int L,R;
	sp(rt,x,L,R);
	cout<<t[kth(R,1)].val<<'\n';
	rt=mg(L,R);
	return ;
}
int main()
{
	srand(time(NULL));
	int n;
	cin>>n;
	while(n--)
	{
		int op,x;
		cin>>op>>x;
		if(op==1)insert(x);
		if(op==2)del(x);
		if(op==3)rnk(x);
		if(op==4)cout<<t[kth(rt,x)].val<<'\n';
		if(op==5)pre(x);
		if(op==6)nxt(x);
	}
	return 0;
}
