#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=1e5+5;
int dis[N];
vector<int>tu[N];
void dfs(int x,int fa,int d)
{
	dis[x]=d;
	for(int i:tu[x])
		if(i!=fa)
			dfs(i,x,d+1);
	return ;
}
signed main()
{
	int n;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		tu[u].push_back(v);
		tu[v].push_back(u);
	}
	dfs(1,0,0);
	int s=0;
	for(int i=1;i<=n;i++)
		if(dis[i]>dis[s])
			s=i;
	dfs(s,0,0);
	int t=0;
	for(int i=1;i<=n;i++)
		if(dis[i]>dis[t])
			t=i;
	cout<<dis[t];
	return 0;
}
