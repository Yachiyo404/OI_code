#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=2e6+5;
int m,n,cnt,id;
int dfn[N],low[N],scc[N];
vector<int>tu[N];
stack<int>S;
void dfs(int x)
{
	dfn[x]=low[x]=++id;
	S.push(x);
	for(int i:tu[x])
	{
		if(!dfn[i])
		{
			dfs(i);
			low[x]=min(low[x],low[i]);
		}
		else if(!scc[i])
			low[x]=min(low[x],dfn[i]);
	}
	if(dfn[x]==low[x])
	{
		cnt++;
		while(S.top()!=x)
		{
			scc[S.top()]=cnt;
			S.pop();
		}
		scc[S.top()]=cnt;
		S.pop();
	}
	return ;
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b,aa,bb;
		cin>>a>>aa>>b>>bb;
		int aaa=aa^1,bbb=bb^1;
		tu[a+n*aaa].push_back(b+n*bb);
		tu[b+n*bbb].push_back(a+n*aa);
	}
	for(int i=1;i<=2*n;i++)
		if(!dfn[i])
			dfs(i);
	bool flag=1;
	for(int i=1;i<=n;i++)
		if(scc[i]==scc[i+n])
		{
			flag=0;
			break;
		}
	if(flag)
	{
		cout<<"POSSIBLE\n";
		for(int i=1;i<=n;i++)
			cout<<(scc[i]>scc[i+n])<<" ";
	}
	else
		cout<<"IMPOSSIBLE";
	return 0;
}
