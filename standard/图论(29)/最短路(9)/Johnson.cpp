#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int cnt[3005],dis1[3005],dis2[3005];
bool vis[3005];
vector<pair<int,int>>tu[3005];
bool SPFA(int s)
{
	queue<int>q;
	for(int i=1;i<=n;i++)
		dis1[i]=1e9;
	dis1[s]=0;
	vis[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		vis[x]=0;
		for(auto i:tu[x])
		{
			int j=i.first,k=i.second;
			if(dis1[j]>dis1[x]+k)
			{
				dis1[j]=dis1[x]+k;
				if(!vis[j])
				{
					cnt[j]++;
					if(cnt[j]>n)
						return 1;
					q.push(j);
					vis[j]=1;
				}
			}
		}
	}
	return 0;
}
void dij(int s)
{
	priority_queue<pair<int,int>>q;
	for(int i=1;i<=n;i++)
		dis2[i]=1e9;
	memset(vis,0,sizeof(vis));
	dis2[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		if(vis[x])
			continue;
		vis[x]=1;
		for(auto i:tu[x])
		{
			int j=i.first,k=i.second;
			if(dis2[j]>dis2[x]+k)
			{
				dis2[j]=dis2[x]+k;
				q.push(make_pair(-dis2[j],j));
			}
		}
	}
	return ;
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		tu[u].push_back(make_pair(v,w));
	}
	for(int i=1;i<=n;i++)
		tu[0].push_back(make_pair(i,0));
	if(SPFA(0))
	{
		cout<<-1;
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(auto &j:tu[i])
		{
			int k=j.first;
			j.second+=(dis1[i]-dis1[k]);
		}
	for(int i=1;i<=n;i++)
	{
		dij(i);
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			if(dis2[j]==1e9)
				ans+=(j*dis2[j]);
			else
				ans+=(j*(dis2[j]+dis1[j]-dis1[i]));
		}
		cout<<ans<<'\n';
	}
	return 0;
}
