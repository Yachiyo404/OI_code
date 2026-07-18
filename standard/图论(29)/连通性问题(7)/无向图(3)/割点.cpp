#include<bits/stdc++.h>
using namespace std;
int n,m,R,id,cnt;
int dfn[20005],low[20005];
bool f[20005];
vector<int>tu[20005];
void dfs(int x)
{
	id++;
	dfn[x]=low[x]=id;
	int son=0;
	for(int i:tu[x])
	{
		if(!dfn[i])
		{
			son++;
			dfs(i);
			low[x]=min(low[x],low[i]);
			if(low[i]>=dfn[x]&&x!=R)
			{
				cnt+=(!f[x]);
				f[x]=1;
			}
		}
		else
			low[x]=min(low[x],dfn[i]);
	}
	if(son>=2&&x==R)
	{
		cnt+=(!f[x]);
		f[x]=1;
	}
	return ;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		tu[u].push_back(v);
		tu[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
		{
			R=i;
			dfs(i);
		}
	cout<<cnt<<'\n';
	for(int i=1;i<=n;i++)
		if(f[i])
			cout<<i<<" ";
	return 0;
}
