#include<bits/stdc++.h>
#define int long long
using namespace std;
int scc[10005],cnt;
bool vis[10005];
vector<int>tu[10005],tsy[10005],S;
void dfs1(int x)
{
	if(vis[x])
		return ;
	vis[x]=1;
	for(int i:tu[x])
		dfs1(i);
	S.push_back(x);
	return ;
}
void dfs2(int x)
{
	if(scc[x])
		return ;
	scc[x]=cnt;
	for(int i:tsy[x])
		dfs2(i);
	return ;
}
signed main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		tu[u].push_back(v);
		tsy[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		dfs1(i);
	for(int i=n-1;i>=0;i--)
		if(!scc[S[i]])
		{
			cnt++;
			dfs2(S[i]);
		}
	for(int i=1;i<=n;i++)
		cout<<scc[i]<<'\n';
    return 0;
}
