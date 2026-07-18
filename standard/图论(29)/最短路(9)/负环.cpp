#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int dis[2005],cnt[2005];
bool vis[2005];
vector<pair<int,int>>tu[2005];
queue<int>q;
bool SPFA()
{
	for(int i=1;i<=n;i++)
		dis[i]=1e9;
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	while(!q.empty())
		q.pop();
	dis[1]=0;
	vis[1]=1;
	q.push(1);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		vis[x]=0;
		for(auto i:tu[x])
		{
			int j=i.first,k=i.second;
			if(dis[j]>dis[x]+k)
			{
				dis[j]=dis[x]+k;
				if(!vis[j])
				{
					cnt[j]++;
					if(cnt[j]>=n)
						return 1;
					q.push(j);
					vis[j]=1;
				}
			}
		}
	}
	return 0;
}
signed main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			tu[i].clear();
		for(int i=1;i<=m;i++)
		{
			int u,v,w;
			cin>>u>>v>>w;
			tu[u].push_back(make_pair(v,w));
			if(w>=0)
				tu[v].push_back(make_pair(u,w));
		}
		if(SPFA())
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
