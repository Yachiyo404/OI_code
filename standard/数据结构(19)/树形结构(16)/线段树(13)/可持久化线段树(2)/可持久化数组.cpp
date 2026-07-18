#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
constexpr int N=1e6+5;
int cnt,a[N],rt[N],c;
struct cxt{int l,r,sum;}t[N<<5];
void bd(int &x,int l,int r)
{
	cnt++;
    x=cnt;
    if(l==r)
	{
		t[x].sum=a[l];
		return;
	}
    int mid=(l+r)>>1;
    bd(t[x].l,l,mid);
	bd(t[x].r,mid+1,r);
	return ;
}
void up(int &x,int l,int r,int num)
{
    t[++cnt]=t[x];
	x=cnt;
    int mid=(l+r)>>1;
    if(l==r)
	{
		t[x].sum=c;
		return;
	}
    if(num<=mid)
		up(t[x].l,l,mid,num);
    else
		up(t[x].r,mid+1,r,num);
	return ;
}
int query(int x,int l,int r,int k)
{
    if(l==r)
		return t[x].sum;
    int mid=(l+r)>>1;
    if(k<=mid)
		return query(t[x].l,l,mid,k);
    else
		return query(t[x].r,mid+1,r,k);
}
signed main()
{
	int n=read(),m=read();
    for(int i=1;i<=n;i++)
		a[i]=read();
    bd(rt[0],1,n);
    for(int i=1;i<=m;i++)
	{
        int v=read(),op=read(),p=read();
        if(op==1)
		{
			c=read();
            rt[i]=rt[v];
            up(rt[i],1,n,p);
        }
		else
		{
            cout<<query(rt[v],1,n,p)<<'\n';
            rt[i]=rt[v];
        }
    }
	return 0;
}
