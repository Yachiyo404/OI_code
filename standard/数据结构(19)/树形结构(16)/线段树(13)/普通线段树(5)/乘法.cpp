#include<bits/stdc++.h>
#define int long long
using namespace std;
struct sb
{
	int l,r,sum,mlz,plz;
}tree[400005];
int a[100005];
int m,n,p,i,j,k;
void build(int i,int l,int r)
{
	tree[i].l=l;
	tree[i].r=r;
	tree[i].mlz=1;
	if(l==r)
	{
		tree[i].sum=a[l]%p;
		return ;
	}
	int mid=(l+r)>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	tree[i].sum=(tree[i<<1].sum+tree[i<<1|1].sum)%p;
	return ;
}
void pushdown(int i)
{
	int k1=tree[i].mlz,k2=tree[i].plz;
	tree[i<<1].sum=(tree[i<<1].sum*k1+k2*(tree[i<<1].r-tree[i<<1].l+1))%p;
	tree[i<<1|1].sum=(tree[i<<1|1].sum*k1+k2*(tree[i<<1|1].r-tree[i<<1|1].l+1))%p;
	tree[i<<1].mlz=(tree[i<<1].mlz*k1)%p;
	tree[i<<1|1].mlz=(tree[i<<1|1].mlz*k1)%p;
	tree[i<<1].plz=(tree[i<<1].plz*k1+k2)%p;
	tree[i<<1|1].plz=(tree[i<<1|1].plz*k1+k2)%p;
	tree[i].plz=0;
	tree[i].mlz=1;
	return ;
}
void mul(int i,int l,int r,int k)
{
	if(tree[i].r<l||tree[i].l>r)
		return ;
	if(tree[i].r<=r&&tree[i].l>=l)
	{
		tree[i].sum=(tree[i].sum*k)%p;
		tree[i].mlz=(tree[i].mlz*k)%p;
		tree[i].plz=(tree[i].plz*k)%p;
		return ;
	}
	pushdown(i);
	if(tree[i<<1].r>=l)
		mul(i<<1,l,r,k);
	if(tree[i<<1|1].l<=r)
		mul(i<<1|1,l,r,k);
	tree[i].sum=(tree[i<<1].sum+tree[i<<1|1].sum)%p;
	return ;
}
void add(int i,int l,int r,int k)
{
	if(tree[i].r<l||tree[i].l>r)
		return ;
	if(tree[i].r<=r&&tree[i].l>=l)
	{
		tree[i].sum+=(k*(tree[i].r-tree[i].l+1))%p;
		tree[i].plz=(tree[i].plz+k)%p;
		return ;
	}
	pushdown(i);
	if(tree[i<<1].r>=l)
		add(i<<1,l,r,k);
	if(tree[i<<1|1].l<=r)
		add(i<<1|1,l,r,k);
	tree[i].sum=(tree[i<<1].sum+tree[i<<1|1].sum)%p;
	return ;
}
int search(int i,int l,int r)
{
	if(tree[i].l>=l&&tree[i].r<=r)
		return tree[i].sum;
	if(tree[i].r<l||tree[i].l>r)
		return 0;
	pushdown(i);
	int s=0;
	if(tree[i<<1].r>=l)
		s+=search(i<<1,l,r)%p;
	if(tree[i<<1|1].l<=r)
		s+=search(i<<1|1,l,r)%p;
	return s%p;
}
signed main()
{
	cin>>n>>p;
	for(i=1;i<=n;i++)
		cin>>a[i];
	cin>>m;
	build(1,1,n);
	while(m--)
	{
		int op,x,y,z;
		cin>>op;
		if(op==1)
		{
			cin>>x>>y>>z;
			z%=p;
			mul(1,x,y,z);
		}
		if(op==2)
		{
			cin>>x>>y>>z;
			z%=p;
			add(1,x,y,z);
		}
		if(op==3)
		{
			cin>>x>>y;
			cout<<search(1,x,y)<<'\n';
		}
	}
	return 0;
}
