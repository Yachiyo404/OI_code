#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=205;
int n,m,s,t,ans;
int now[N],deep[N];
struct cxt{int v,w,id;};
vector<cxt>tu[N];
void bfs()
{
	memset(deep,-1,sizeof(deep));
	deep[t]=0;
	now[0]=1;
	queue<int>q;
	q.push(t);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(cxt i:tu[x])
		{
			int v=i.v;
			if(deep[v]==-1)
			{
				deep[v]=deep[x]+1;
				now[deep[v]]++;
				q.push(v);
			}
		}
	}
	return ;
}
int dfs(int x,int sum)
{
	if(x==t)
	{
		ans+=sum;
		return sum;
	}
	int used=0;
	for(cxt &i:tu[x])
	{
		int v=i.v;
		if(deep[v]+1==deep[x])
		{
			int num=dfs(v,min(i.w,sum-used));
			if(num)
			{
				i.w-=num;
				tu[v][i.id].w+=num;
				used+=num;
			}
			if(used==sum)
				return used;
		}
	}
	now[deep[x]]--;
	if(now[deep[x]]==0)
		deep[s]=n+1;
	deep[x]++;
	now[deep[x]]++;
	return used;
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
    bfs();
    while(deep[s]<n)
        dfs(s,(int)1e18);
    cout<<ans;
	return 0;
}
