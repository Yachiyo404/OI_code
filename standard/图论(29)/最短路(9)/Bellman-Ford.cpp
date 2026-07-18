#include<bits/stdc++.h>
#define int long long
using namespace std;
struct cxt{int u,v,w;}tu[20005];
int dis[10005];
signed main()
{
	int n,m,s;
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++)
		cin>>tu[i].v>>tu[i].u>>tu[i].w;
	for(int i=1;i<=n;i++)
		dis[i]=1e18;
	dis[s]=0;
	for(int I=1;I<=n;I++)
	{
		for(int i=1;i<=m;i++)
		{
			int x=tu[i].u,y=tu[i].v,z=tu[i].w;
			dis[x]=min(dis[x],dis[y]+z);
		}
	}
	for(int i=1;i<=n;i++)
		cout<<dis[i]<<" ";
    return 0;
}
