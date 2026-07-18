#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=205;
int n,m,s,t;
int now[N],deep[N];
struct cxt{int v,w,id;};
vector<cxt>tu[N];
bool bfs()
{
	memset(deep,-1,sizeof(deep));
	deep[s]=0;
	queue<int>q;
	q.push(s);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(cxt i:tu[x])
		{
			int v=i.v;
			if(deep[v]==-1&&i.w)
			{
				deep[v]=deep[x]+1;
				q.push(v);
			}
		}
	}
	memset(now,0,sizeof(now));
	return (deep[t]!=-1);
}
int dfs(int x,int sum)
{
	if(x==t)
		return sum;
	for(int i=now[x];i<tu[x].size();i++)
	{
		now[x]=i;
		int v=tu[x][i].v;
		if(deep[v]==deep[x]+1&&tu[x][i].w)
		{
			int num=dfs(v,min(tu[x][i].w,sum));
			if(num)
			{
				tu[x][i].w-=num;
				tu[v][tu[x][i].id].w+=num;
				return num;
			}
			else
				deep[v]=-1;
		}
	}
	return 0;
}
signed main()
{
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		int a=tu[u].size(),b=tu[v].size();
		tu[u].push_back((cxt){v,w,b});
		tu[v].push_back((cxt){u,0,a});
	}
	int ans=0;
	while(bfs())
		ans+=dfs(s,(int)1e18);
	cout<<ans;
	return 0;
}
