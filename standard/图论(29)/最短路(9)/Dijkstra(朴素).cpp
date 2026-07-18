#include<bits/stdc++.h>
#define int long long
using namespace std;
int dis[2505];
bool vis[2505];
vector<pair<int,int>>tu[2505];
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
	for(int i=1;i<=n;i++)
	{
		int pos=0;
		for(int j=1;j<=n;j++)
		{
			if(!pos&&!vis[j])
			{
				pos=j;
				continue;
			}
			if(!vis[j]&&dis[pos]>dis[j])
				pos=j;
		}
		vis[pos]=1;
		for(auto j:tu[pos])
		{
			int k=j.first,w=j.second;
			dis[k]=min(dis[k],dis[pos]+w);
		}
	}
	cout<<dis[n];
    return 0;
}
