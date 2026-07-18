#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=205;
int n,m;
int tu[N][N],pre[N],flow[N];
int bfs(int s,int t)
{
	memset(pre,-1,sizeof(pre));
	flow[s]=1e18;
	pre[s]=0;
	queue<int>q;
	q.push(s);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		if(x==t)
			break;
		for(int i=1;i<=n;i++)
			if(i!=s&&tu[x][i]&&pre[i]==-1)
			{
				pre[i]=x;
				q.push(i);
				flow[i]=min(flow[x],tu[x][i]);
			}
	}
	if(pre[t]==-1)
		return -1;
	return flow[t];
}
signed main()
{
	int s,t;
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		tu[u][v]+=w;
	}
	int ans=0;
	while(1)
	{
		int sum=bfs(s,t);
		if(sum==-1)
			break;
		int x=t;
		while(x!=s)
		{
			int fa=pre[x];
			tu[fa][x]-=sum;
			tu[x][fa]+=sum;
			x=fa;
		}
		ans+=sum;
	}
	cout<<ans;
	return 0;
}
