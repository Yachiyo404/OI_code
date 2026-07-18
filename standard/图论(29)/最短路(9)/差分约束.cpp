#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>tu[5005];
queue<int>q;
int n,m;
int cnt[5005],dis[5005];
bool vis[5005];
bool SPFA(int s)
{
	cnt[s]=1;
	for(int i=0;i<=n;i++)
		dis[i]=1e9;
	dis[s]=0;
	q.push(s);
	vis[s]=1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		vis[x]=0;
		for(auto i:tu[x])
		{
			int j=i.first,k=i.second;
			if(dis[x]+k<dis[j])
			{
				dis[j]=dis[x]+k;
				if(!vis[j])
				{
					vis[j]=1;
					q.push(j);
					cnt[j]++;
					if(cnt[j]>n)
						return 1;
				}
			}
		}
	}
	return 0;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		tu[0].push_back(make_pair(i,0));
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		tu[v].push_back(make_pair(u,w));
	}
	if(SPFA(0))
		cout<<"NO";
	else
		for(int i=1;i<=n;i++)
			cout<<dis[i]<<" ";
	return 0;
}
//xi<=xj+w ---> xj->xi(w)
