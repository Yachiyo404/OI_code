#include<bits/stdc++.h>
using namespace std;
int g[105][105];
int main()
{
	int n,m;
	cin>>n>>m;
	memset(g,51,sizeof(g));
	for(int i=1;i<=n;i++)
		g[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u][v]=w;
		g[v][u]=w;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<g[i][j]<<" ";
		cout<<'\n';
	}
	return 0;
}
