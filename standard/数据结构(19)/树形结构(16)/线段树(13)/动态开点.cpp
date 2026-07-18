#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
struct cxt
{
    int l,r,ls,rs;
    ull sum,add;
}tree[10000005];
int cnt=1,n,m;
ull getsum(int l,int r)
{
    return (ull)r*(r+1)/2-(ull)(l-1)*l/2;
}
void pd(int x)
{
    int mid=(tree[x].l+tree[x].r)/2;
    if(!tree[x].ls)
	{
        tree[x].ls=++cnt;
        tree[cnt].l=tree[x].l;
        tree[cnt].r=mid;
        tree[cnt].sum=getsum(tree[cnt].l,tree[cnt].r);
        tree[cnt].add=0;
    }
    tree[tree[x].ls].sum+=tree[x].add*(tree[tree[x].ls].r-tree[tree[x].ls].l+1);
    tree[tree[x].ls].add+=tree[x].add;
    if(!tree[x].rs)
	{
        tree[x].rs=++cnt;
        tree[cnt].l=mid+1;
        tree[cnt].r=tree[x].r;
        tree[cnt].sum=getsum(tree[cnt].l,tree[cnt].r);
        tree[cnt].add=0;
    }
    tree[tree[x].rs].sum+=tree[x].add*(tree[tree[x].rs].r-tree[tree[x].rs].l+1);
    tree[tree[x].rs].add+=tree[x].add;
    tree[x].add=0;
    return ;
}
void add(int x,int l,int r,int k)
{
    if(tree[x].r<l||tree[x].l>r)
        return ;
    if(l<=tree[x].l&&tree[x].r<=r)
	{
        tree[x].sum+=(ull)k*(tree[x].r-tree[x].l+1);
        tree[x].add+=k;
        return ;
    }
    pd(x);
    add(tree[x].ls,l,r,k);
    add(tree[x].rs,l,r,k);
    tree[x].sum=tree[tree[x].ls].sum+tree[tree[x].rs].sum;
    return ;
}
ull query(int x,int l,int r)
{
    if(tree[x].r<l||tree[x].l>r)
        return 0;
    if(l<=tree[x].l&&tree[x].r<=r)
        return tree[x].sum;
    pd(x);
    return query(tree[x].ls,l,r)+query(tree[x].rs,l,r);
}
int main()
{
    cin>>n>>m;
    tree[1].l=1;
    tree[1].r=n;
    tree[1].sum=getsum(1,n);
    tree[1].add=0;
    while(m--)
	{
        int op,l,r;
        ull k;
        cin>>op>>l>>r;
        if(op==1)
		{
            cin>>k;
            add(1,l,r,k);
        }
		else
            cout<<query(1,l,r)<<'\n';
    }
    return 0;
}
