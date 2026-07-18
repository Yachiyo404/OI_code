#include<bits/stdc++.h>
#define int long long
using namespace std;
int dis[2505];
bool vis[2505];
vector<pair<int,int>>tu[2505];
queue<int>q;
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
					q.push(j);
					vis[j]=1;
				}
			}
		}
	}
	cout<<dis[n];
    return 0;
}
