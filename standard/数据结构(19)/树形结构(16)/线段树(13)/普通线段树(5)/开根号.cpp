#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
    int l,r,lz,sum,maxx,minn;
}tree[400005];
int n,m,a[100005];
void build(int i,int l,int r)
{
    tree[i].l=l;
	tree[i].r=r;
    if(l==r)
	{
        tree[i].sum=a[l];
		tree[i].minn=a[l];
		tree[i].maxx=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
    tree[i].minn=min(tree[i*2].minn,tree[i*2+1].minn);
    tree[i].maxx=max(tree[i*2].maxx,tree[i*2+1].maxx);
    return ;
}
void push_down(int i)
{
    if(!tree[i].lz)
		return ;
    int k=tree[i].lz;
    tree[i*2].lz+=k;
    tree[i*2+1].lz+=k;
    tree[i*2].sum-=(tree[i*2].r-tree[i*2].l+1)*k;
    tree[i*2+1].sum-=(tree[i*2+1].r-tree[i*2+1].l+1)*k;
    tree[i*2].minn-=k;
    tree[i*2+1].minn-=k;
    tree[i*2].maxx-=k;
    tree[i*2+1].maxx-=k;
    tree[i].lz=0;
    return ;
}
void s(int i,int l,int r)
{
    if(tree[i].l>=l&&tree[i].r<=r&&(tree[i].minn-(int)sqrt(tree[i].minn))==(tree[i].maxx-(int)sqrt(tree[i].maxx)))
	{
        int u=tree[i].minn-(int)sqrt(tree[i].minn);
        tree[i].lz+=u;
        tree[i].sum-=(tree[i].r-tree[i].l+1)*u;
        tree[i].minn-=u;
        tree[i].maxx-=u;
        return ;
    }
    if(tree[i].r<l||tree[i].l>r)
		return ;
    push_down(i);
    if(tree[i*2].r>=l)
		s(i*2,l,r);
    if(tree[i*2+1].l<=r)
		s(i*2+1,l,r);
    tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
    tree[i].minn=min(tree[i*2].minn,tree[i*2+1].minn);
    tree[i].maxx=max(tree[i*2].maxx,tree[i*2+1].maxx);
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
    cin>>n;
    for(int i=1;i<=n;i++)
		cin>>a[i];
    build(1,1,n);
    cin>>m;
    for(int i=1;i<=m;i++)
	{
		int k,l,r;
        cin>>k>>l>>r;
        if(l>r)
        	swap(l,r);
        if(k==0)
            s(1,l,r);
        if(k==1)
            cout<<search(1,l,r)<<'\n';
    }
    return 0;
}
