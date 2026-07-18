#include<bits/stdc++.h>
#define int long long
#define alpha 0.75
using namespace std;
const int N=1e5+5;
struct cxt
{
	int ls,rs,val,tot,size;
	bool del;
}t[N];
int order[N],cnt,rt;
stack<int>S;
void Sort(int u)
{
	if(!u)
		return ;
	Sort(t[u].ls);
	if(t[u].del)
		order[++cnt]=u;
	else
		S.push(u);
	Sort(t[u].rs);
	return ;
}
void init(int u)
{
	t[u].ls=0;
	t[u].rs=0;
	t[u].size=1;
	t[u].tot=1;
	t[u].del=1;
	return ;
}
void upd(int u)
{
	t[u].size=t[t[u].ls].size+t[t[u].rs].size+1;
	t[u].tot=t[t[u].ls].tot+t[t[u].rs].tot+1;
	return ;
}
void bd(int l,int r,int &u)
{
	int mid=(l+r)>>1;
	u=order[mid];
	if(l==r)
	{
		init(u);
		return ;
	}
	if(l<mid)
		bd(l,mid-1,t[u].ls);
	if(l==mid)
		t[u].ls=0;
	bd(mid+1,r,t[u].rs);
	upd(u);
	return ;
}
void rebd(int &u)
{
	cnt=0;
	Sort(u);
	if(cnt)
		bd(1,cnt,u);
	else
		u=0;
	return ;
}
bool ck(int u)
{
	if((double)t[u].size*alpha<=(double)max(t[t[u].ls].size,t[t[u].rs].size))
		return 1;
	return 0;
}
void Insert(int &u,int x)
{
	if(!u)
	{
		u=S.top();
		S.pop();
		t[u].val=x;
		init(u);
		return ;
	}
	t[u].size++;
	t[u].tot++;
	if(t[u].val>=x)
		Insert(t[u].ls,x);
	else
		Insert(t[u].rs,x);
	if(ck(u))
		rebd(u);
	return ;
}
int rk(int u,int x)
{
	if(u==0)
		return 0;
	if(x>t[u].val)
		return t[t[u].ls].size+t[u].del+rk(t[u].rs,x);
	return rk(t[u].ls,x);
}
int kth(int k)
{
	int u=rt;
	while(u)
	{
		if(t[u].del&&t[t[u].ls].size+1==k)
			return t[u].val;
		else if(t[t[u].ls].size>=k)
			u=t[u].ls;
		else
		{
			k-=(t[t[u].ls].size+t[u].del);
			u=t[u].rs;
		}
	}
	return t[u].val;
}
void delk(int &u,int k)
{
	t[u].size--;
	if(t[u].del&&t[t[u].ls].size+1==k)
	{
		t[u].del=0;
		return ;
	}
	if(t[t[u].ls].size+t[u].del>=k)
		delk(t[u].ls,k);
	else
		delk(t[u].rs,k-t[t[u].ls].size-t[u].del);
	return ;
}
void dele(int x)
{
	delk(rt,rk(rt,x)+1);
	if(t[rt].tot*alpha>=t[rt].size)
		rebd(rt);
	return ;
}
signed main()
{
	for(int i=N-1;i;i--)
		S.push(i);
	int q;
	cin>>q;
	while(q--)
	{
		int op,x;
		cin>>op>>x;
		if(op==1)
			Insert(rt,x);//插入
		if(op==2)
			dele(x);//删除
		if(op==3)
			cout<<rk(rt,x)+1<<'\n';//x的排名
		if(op==4)
			cout<<kth(x)<<'\n';//排第x位的数
		if(op==5)
			cout<<kth(rk(rt,x))<<'\n';//前驱:小于x且最大
		if(op==6)
			cout<<kth(rk(rt,x+1)+1)<<'\n';//后继:大于x且最小
	}
	return 0;
}
