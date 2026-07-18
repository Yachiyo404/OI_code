#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,r,mod;
int w[100005],ww[100005];
struct cxt
{
	int sum,lz;
}tree[400005];
int ls(int x){return x<<1;}
int rs(int x){return x<<1|1;}
void push_up(int x)
{
	tree[x].sum=tree[ls(x)].sum+tree[rs(x)].sum;
	tree[x].sum%=mod;
	return ;
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		tree[x].sum=ww[l];
		tree[x].sum%=mod;
		return ;
	}
	int mid=(l+r)>>1;
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
	push_up(x);
	return ;
}
void push_down(int x,int l,int r)
{
	if(tree[x].lz)
	{
		int k=tree[x].lz,mid=(l+r)>>1;
		tree[ls(x)].lz+=k;
		tree[ls(x)].sum+=k*(mid-l+1);
		tree[ls(x)].sum%=mod;
		tree[rs(x)].lz+=k;
		tree[rs(x)].sum+=k*(r-mid);
		tree[rs(x)].sum%=mod;
		tree[x].lz=0;
	}
	return ;
}
void add(int x,int tl,int tr,int l,int r,int val)
{
	if(tl>=l&&tr<=r)
	{
		tree[x].lz+=val;
		tree[x].sum+=val*(tr-tl+1);
		tree[x].sum%=mod;
		return ;
	}
	push_down(x,tl,tr);
	int mid=(tl+tr)>>1;
	if(l<=mid)
		add(ls(x),tl,mid,l,r,val);
	if(r>mid)
		add(rs(x),mid+1,tr,l,r,val);
	push_up(x);
	return ;
}
int query(int x,int tl,int tr,int l,int r)
{
	if(tl>=l&&tr<=r)
		return tree[x].sum;
	push_down(x,tl,tr);
	int sum=0,mid=(tl+tr)>>1;
	if(l<=mid)
	{
		sum+=query(ls(x),tl,mid,l,r);
		sum%=mod;
	}
	if(r>mid)
	{
		sum+=query(rs(x),mid+1,tr,l,r);
		sum%=mod;
	}
	return sum;
}
int son[100005],id[100005],fa[100005],deep[100005],sz[100005],top[100005];
vector<int>tu[100005];
void dfs1(int x,int f)
{
	deep[x]=deep[f]+1;
	fa[x]=f;
	sz[x]=1;
	for(int i:tu[x])
	{
		if(i!=f)
		{
			dfs1(i,x);
			sz[x]+=sz[i];
			if(sz[son[x]]<sz[i])
				son[x]=i;
		}
	}
	return ;
}
int num;
void dfs2(int x,int tp)
{
	num++;
	id[x]=num;
	ww[num]=w[x];
	top[x]=tp;
	if(!son[x])
		return ;
	dfs2(son[x],tp);
	for(int i:tu[x])
		if(i!=fa[x]&&i!=son[x])
			dfs2(i,i);
	return ;
}
void add1(int x,int y,int z)
{
	while(top[x]!=top[y])
	{
		if(deep[top[x]]<deep[top[y]])
			swap(x,y);
		add(1,1,n,id[top[x]],id[x],z);
		x=fa[top[x]];
	}
	if(deep[x]>deep[y])
		swap(x,y);
	add(1,1,n,id[x],id[y],z);
	return ;
}
int query1(int x,int y)
{
	int sum=0;
	while(top[x]!=top[y])
	{
		if(deep[top[x]]<deep[top[y]])
			swap(x,y);
		sum+=query(1,1,n,id[top[x]],id[x]);
		sum%=mod;
		x=fa[top[x]];
	}
	if(deep[x]>deep[y])
		swap(x,y);
	sum+=query(1,1,n,id[x],id[y]);
	sum%=mod;
	return sum;
}
void add2(int x,int val){add(1,1,n,id[x],id[x]+sz[x]-1,val);return ;}
int query2(int x){return query(1,1,n,id[x],id[x]+sz[x]-1);}
signed main()
{
	cin>>n>>m>>r>>mod;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		tu[u].push_back(v);
		tu[v].push_back(u);
	}
	dfs1(r,0);
	dfs2(r,r);
	build(1,1,n);
	while(m--)
	{
		int op,x,y,z;
		cin>>op;
		if(op==1)
		{
			cin>>x>>y>>z;
			add1(x,y,z);
		}
		else if(op==2)
		{
			cin>>x>>y;
			cout<<query1(x,y)<<'\n';
		}
		else if(op==3)
		{
			cin>>x>>y;
			add2(x,y);
		}
		else
		{
			cin>>x;
			cout<<query2(x)<<'\n';
		}
	}
    return 0;
}
