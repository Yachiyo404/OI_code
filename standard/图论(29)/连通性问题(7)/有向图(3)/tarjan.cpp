#include<bits/stdc++.h>
using namespace std;
int m,n,cnt,id;
int dfn[100005],low[100005],scc[100005];
vector<int>tu[100005];
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
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int p,q;
		cin>>p>>q;
		tu[p].push_back(q);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			dfs(i);
	for(int i=1;i<=n;i++)
		cout<<scc[i]<<'\n';
	return 0;
}
