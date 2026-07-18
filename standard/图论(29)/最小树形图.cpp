#include<bits/stdc++.h>
using namespace std;
struct cxt
{
    int p,q,r;
}a[100005];
int m,n,rt,ffl,ans,lfl,plp,nfl,nans;
int b[1005][1005],vis[10005],lp[1005][1005],nplp[10005],tlp[10005],fa[10005],faq[10005],dis[10005];
int main()
{
	cin>>n>>m>>rt;
	rt--;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			b[i][j]=99999999;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].p>>a[i].q>>a[i].r;
		a[i].p--;
		a[i].q--;
		b[a[i].p][a[i].q]=a[i].r;
	}
	while(1)
	{
		for(int i=0;i<n;i++)
			faq[i]=99999999;
		for(int i=1;i<=m;i++)
		{
			int np=a[i].p,nq=a[i].q;
			if(a[i].r<faq[nq]&&np!=nq)
			{
				fa[nq]=np;
				faq[nq]=a[i].r;
			}
		}
		for(int i=0;i<n;i++)
		{
			if(i==rt)
				continue;
			if(faq[i]>=99999999)
			{
				ffl=1;
				break;
			}
		}
		int cnt=0;
		memset(vis,-1,sizeof(vis));
		memset(tlp,-1,sizeof(tlp));
		faq[rt]=0;
		for(int i=0;i<n;i++)
		{
			ans+=faq[i];
			int v=i;
			while(v!=rt&&tlp[v]==-1&&vis[v]!=i)
			{
				vis[v]=i;
				v=fa[v];
			}
			if(v!=rt&&tlp[v]==-1)
			{
				int u=fa[v];
				do
				{
					tlp[u]=cnt;
					u=fa[u];
				}
				while(u!=v);
				tlp[v]=cnt++;
			}
		}
		if(cnt==0)
			break;
		for(int i=0;i<n;i++)
			if(tlp[i]==-1)
				tlp[i]=cnt++;
		for(int i=1;i<=m;i++)
		{
			int np=a[i].p,nq=a[i].q;
			a[i].p=tlp[a[i].p];
			a[i].q=tlp[a[i].q];
			if(tlp[np]!=tlp[nq])
				a[i].r-=faq[nq];
		}
		n=cnt;
		rt=tlp[rt];
	}
	if(ffl)
		cout<<-1;
	else
		cout<<ans;
    return 0;
}
