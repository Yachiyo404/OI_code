#include<bits/stdc++.h>
#define int long long
using namespace std;
int dis[2505];
bool vis[2505];
vector<pair<int,int>>tu[2505];
priority_queue<pair<int,int>>q;
signed main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		tu[u].push_back(make_pair(v,w));
		tu[v].push_back(make_pair(u,w));
	}
	for(int i=1;i<=n;i++)
		dis[i]=1e9;
	dis[1]=0;
	q.push(make_pair(0,1));
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
			if(dis[j]>dis[x]+k)
			{
				dis[j]=dis[x]+k;
				q.push(make_pair(-dis[j],j));
			}
		}
	}
	cout<<dis[n];
    return 0;
}
