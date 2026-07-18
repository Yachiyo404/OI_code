#include<bits/stdc++.h>
#define int long long
using namespace std;
int id,cnt;
int dfn[500005],low[500005],deg[500005];
vector<int>tu[500005],ans[500005];
stack<int>S;
void dfs(int x,int fa)
{
	id++;
	dfn[x]=low[x]=id;
	S.push(x);
	if(!deg[x])
		ans[++cnt].push_back(x);
	for(int i:tu[x])
	{
		if(!dfn[i])
		{
			dfs(i,x);
			low[x]=min(low[x],low[i]);
			if(low[i]>=dfn[x])
			{
				cnt++;
				int t=S.top();
				S.pop();
				ans[cnt].push_back(t);
				while(t!=i)
				{
					t=S.top();
					S.pop();
					ans[cnt].push_back(t);
				}
				ans[cnt].push_back(x);
			}
		}
		else
			low[x]=min(low[x],dfn[i]);
	}
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
		if(u==v)
			continue;
		tu[u].push_back(v);
		tu[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			dfs(i,i);
	cout<<cnt<<'\n';
	for(int i=1;i<=cnt;i++)
	{
		cout<<ans[i].size()<<" ";
		for(int j:ans[i])
			cout<<j<<" ";
		cout<<'\n';
	}
	return 0;
}
