#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
int m,n,i,j,k,q;
struct sb
{
	int l,r,sum,lz,minn;
}tree[800005];
void build(int i,int l,int r)
{
	tree[i].l=l;
	tree[i].r=r;
	if(l==r)
	{
		tree[i].sum=a[l];
		tree[i].minn=a[l];
		return ;
	}
	int mid=(l+r)/2;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
	tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
	tree[i].minn=min(tree[i*2].minn,tree[i*2+1].minn);
}
void push_down(int i)
{
	if(tree[i].lz!=0)
	{
		tree[i*2].lz+=tree[i].lz;
		tree[i*2].sum+=tree[i].lz*(tree[i*2].r-tree[i*2].l+1);
		tree[i*2].minn+=tree[i].lz;
		tree[i*2+1].lz+=tree[i].lz;
		tree[i*2+1].sum+=tree[i].lz*(tree[i*2+1].r-tree[i*2+1].l+1);
		tree[i*2+1].minn+=tree[i].lz;
		tree[i].lz=0;
	}
	return ;
}
void add(int i,int l,int r,int k)
{
	if(tree[i].r<=r&&tree[i].l>=l)
	{
		tree[i].sum+=k*(tree[i].r-tree[i].l+1);
		tree[i].minn+=k;
		tree[i].lz+=k;
		return ;
	}
	push_down(i);
	if(tree[i*2].r>=l)
		add(i*2,l,r,k);
	if(tree[i*2+1].l<=r)
		add(i*2+1,l,r,k);
	tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
	tree[i].minn=min(tree[i*2].minn,tree[i*2+1].minn);
	return ;
}
int search(int i,int l,int r)
{
	if(tree[i].l>=l&&tree[i].r<=r)
		return tree[i].sum;
	if(tree[i].r<l||tree[i].l>r)
		return 0;
	push_down(i);
	int s=0;
	if(tree[i*2].r>=l)
		s+=search(i*2,l,r);
	if(tree[i*2+1].l<=r)
		s+=search(i*2+1,l,r);
	return s;
}
int query(int i,int l,int r)
{
	if(tree[i].l>=l&&tree[i].r<=r)
		return tree[i].minn;
	if(tree[i].r<l||tree[i].l>r)
		return LONG_LONG_MAX;
	push_down(i);
	int s=min(query(i*2,l,r),query(i*2+1,l,r));
	return s;
}
signed main()
{
	cin>>n>>q;
	for(i=1;i<=n;i++)
		cin>>a[i];
	build(1,1,n);
	while(q--)
	{
		int x,y,z;
		char op;
		cin>>op;
		if(op=='M')
		{
			cin>>x>>y;
			cout<<query(1,x,y)<<'\n';
		}
		if(op=='P')
		{
			cin>>x>>y>>z;
			add(1,x,y,z);
		}
		if(op=='S')
		{
			cin>>x>>y;
			cout<<search(1,x,y)<<'\n';
		}
	}
	return 0;
}
