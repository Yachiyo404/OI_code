#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100005];
struct cxt
{
    int l,r,lz,sum;
}tree[400005];
int ls(int x){return x<<1;}
int rs(int x){return x<<1|1;}
void push_up(int x){tree[x].sum=tree[ls(x)].sum+tree[rs(x)].sum;return ;}
void build(int x,int l,int r)
{
    tree[x].l=l;
    tree[x].r=r;
    if(l==r)
    {
        tree[x].sum=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(ls(x),l,mid);
    build(rs(x),mid+1,r);
    push_up(x);
    return ;
}
void push_down(int x)
{
    int k=tree[x].lz;
    if(k)
    {
        tree[ls(x)].sum+=(tree[ls(x)].r-tree[ls(x)].l+1)*k;
        tree[ls(x)].lz+=k;
        tree[rs(x)].sum+=(tree[rs(x)].r-tree[rs(x)].l+1)*k;
        tree[rs(x)].lz+=k;
        tree[x].lz=0;
    }
    return ;
}
void add(int x,int l,int r,int k)
{
    if(tree[x].l>=l&&tree[x].r<=r)
    {
        tree[x].sum+=(tree[x].r-tree[x].l+1)*k;
        tree[x].lz+=k;
        return ;
    }
    push_down(x);
    if(tree[ls(x)].r>=l)
        add(ls(x),l,r,k);
    if(tree[rs(x)].l<=r)
        add(rs(x),l,r,k);
    push_up(x);
    return ;
}
int query(int x,int l,int r)
{
    if(tree[x].l>=l&&tree[x].r<=r)
        return tree[x].sum;
    if(tree[x].l>r||tree[x].r<l)
        return 0;
    push_down(x);
    int s=0;
    if(tree[ls(x)].r>=l)
        s+=query(ls(x),l,r);
    if(tree[rs(x)].l<=r)
        s+=query(rs(x),l,r);
    return s;
}
signed main()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    build(1,1,n);
    while(q--)
    {
        int op,x,y,z;
        cin>>op;
        if(op==1)
        {
            cin>>x>>y>>z;
            add(1,x,y,z);
        }
        if(op==2)
        {
            cin>>x>>y;
            cout<<query(1,x,y)<<'\n';
        }
    }
    return 0;
}
