#include<bits/stdc++.h>
#define int long long
using namespace std;
int id,dfn[500005],low[500005];
vector<pair<int,int>>tu[500005];
vector<vector<int>>ans;
stack<int>S;
void dfs(int x,int fa)
{
	id++;
	dfn[x]=low[x]=id;
	S.push(x);
	for(auto i:tu[x])
	{
		if(i.second==(fa^1))
			continue;
		if(!dfn[i.first])
		{
			dfs(i.first,i.second);
			low[x]=min(low[x],low[i.first]);
		}
		else
			low[x]=min(low[x],dfn[i.first]);
	}
	if(dfn[x]==low[x])
	{
		vector<int>v;
		v.push_back(x);
		while(S.top()!=x)
		{
			v.push_back(S.top());
			S.pop();
		}
		S.pop();
		ans.push_back(v);
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
		tu[u].push_back(make_pair(v,i<<1));
		tu[v].push_back(make_pair(u,i<<1|1));
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			dfs(i,0);
	cout<<ans.size()<<'\n';
	for(auto i:ans)
	{
		cout<<i.size()<<" ";
		for(int j:i)
			cout<<j<<" ";
		cout<<'\n';
	}
	return 0;
}
