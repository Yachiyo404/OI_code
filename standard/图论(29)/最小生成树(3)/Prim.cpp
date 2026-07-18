#include<bits/stdc++.h>
#define int long long
using namespace std;
int dis[5005];
bool vis[5005];
vector<pair<int,int>>tu[5005];
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
	for(int i=2;i<=n;i++)
		dis[i]=1e18;
	for(auto i:tu[1])
		dis[i.first]=min(dis[i.first],i.second);
	int cnt=1,now=1,ans=0;
	bool flag=1;
	while(cnt<n)
	{
		int minn=1e18;
		vis[now]=1;
		for(int i=1;i<=n;i++)
			if(!vis[i]&&minn>dis[i])
			{
				minn=dis[i];
				now=i;
			}
		if(minn==1e18)
		{
			flag=0;
			break;
		}
		ans+=minn;
		for(auto i:tu[now])
		{
			int j=i.first,w=i.second;
			if(dis[j]>w&&!vis[j])
				dis[j]=w;
		}
		cnt++;
	}
	if(flag)
		cout<<ans;
	else
		cout<<"orz";
	return 0;
}
