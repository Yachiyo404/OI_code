#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=2e5+5;
int cnt,a[N],b[N],rt[N];
struct cxt{int l,r,sum;}t[N<<5];
int up(int x,int l,int r,int k)
{
	cnt++;
	int root=cnt;
	t[root].l=t[x].l;
	t[root].r=t[x].r;
	t[root].sum=t[x].sum+1;
	int mid=(l+r)>>1;
	if(l<r)
	{
		if(k<=mid)
			t[root].l=up(t[x].l,l,mid,k);
		else
			t[root].r=up(t[x].r,mid+1,r,k);
	}
	return root;
}
int query(int L,int R,int l,int r,int k)
{
	if(l==r)
		return l;
	int x=t[t[R].l].sum-t[t[L].l].sum,mid=(l+r)>>1;
	if(x>=k)
		return query(t[L].l,t[R].l,l,mid,k);
	else
		return query(t[L].r,t[R].r,mid+1,r,k-x);
}
signed main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	int sz=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++)
	{
		int x=lower_bound(b+1,b+sz+1,a[i])-b;
		rt[i]=up(rt[i-1],1,sz,x);
	}
	while(m--)
	{
		int x,y,k;
		cin>>x>>y>>k;
		int t=query(rt[x-1],rt[y],1,sz,k);
		cout<<b[t]<<'\n';
	}
	return 0;
}
