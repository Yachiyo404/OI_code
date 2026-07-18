#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
int m,n,i,j,k;
string s;
struct sb
{
	int l,r,sum,lz;
}tree[800005];
void build(int i,int l,int r)
{
	tree[i].l=l;
	tree[i].r=r;
	if(l==r)
	{
		tree[i].sum=a[l];
		return ;
	}
	int mid=(l+r)/2;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
	tree[i].sum=tree[i*2].sum+tree[i*2+1].sum; 
}
void push_down(int i)
{
	if(tree[i].lz!=0)
	{
		tree[i*2].lz^=1;
		tree[i*2].sum=tree[i*2].r-tree[i*2].l+1-tree[i*2].sum;
		tree[i*2+1].lz^=1;
		tree[i*2+1].sum=tree[i*2+1].r-tree[i*2+1].l+1-tree[i*2+1].sum;
		tree[i].lz=0;
	}
	return ;
}
void add(int i,int l,int r)
{
	if(tree[i].r<=r&&tree[i].l>=l)
	{
		tree[i].sum=tree[i].r-tree[i].l+1-tree[i].sum;
		tree[i].lz^=1;
		return ;
	}
	push_down(i);
	if(tree[i*2].r>=l)
		add(i*2,l,r);
	if(tree[i*2+1].l<=r)
		add(i*2+1,l,r);
	tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
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
signed main()
{
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(i=1;i<=n;i++)
		a[i]=s[i]-48;
	build(1,1,n);
	while(m--)
	{
		int op,x,y;
		cin>>op;
		if(op==0)
		{
			cin>>x>>y;
			add(1,x,y);
		}
		if(op==1)
		{
			cin>>x>>y;
			cout<<search(1,x,y)<<'\n';
		}
	}
	return 0;
}
