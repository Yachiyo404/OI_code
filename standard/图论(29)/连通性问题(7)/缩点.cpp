#include<bits/stdc++.h>
using namespace std;
int n,m,id,ans;
int a[10005],dp[10005],u[100005],v[100005],dfn[10005],low[10005],shuyu[10005],in[10005];
bool vis[10005];
vector<int>tu[10005],tsy[10005];
stack<int>S;
queue<int>q;
void dfs(int x)
{
	id++;
	low[x]=dfn[x]=id;
	S.push(x);
	vis[x]=1;
	for(int i:tu[x])
	{
		if(!dfn[i])
		{
			dfs(i);
			low[x]=min(low[x],low[i]);
		}
		else if(vis[i])
			low[x]=min(low[x],dfn[i]);
	}
	if(dfn[x]==low[x])
	{
		while(!S.empty())
		{
			int y=S.top();
			S.pop();
			shuyu[y]=x;
			vis[y]=0;
			if(x==y)
				break;
			a[x]+=a[y];
		}
	}
	return ;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i];
		tu[u[i]].push_back(v[i]);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			dfs(i);
	for(int i=1;i<=m;i++)
	{
		int x=shuyu[u[i]],y=shuyu[v[i]];
		if(x!=y)
		{
			tsy[x].push_back(y);
			in[y]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(shuyu[i]==i&&!in[i])
		{
			q.push(i);
			dp[i]=a[i];
		}
	}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i:tsy[x])
		{
			dp[i]=max(dp[i],dp[x]+a[i]);
			in[i]--;
			if(!in[i])
				q.push(i);
		}
	}
	for(int i=1;i<=n;i++)
		ans=max(ans,dp[i]);
	cout<<ans;
	return 0;
}
