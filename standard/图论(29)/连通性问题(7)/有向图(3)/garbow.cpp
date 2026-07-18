#include<bits/stdc++.h>
#define int long long
using namespace std;
int cnt,id;
int scc[10005],low[10005];
vector<int>tu[10005];
stack<int>S1,S2;
void dfs(int x)
{
	S1.push(x);
	S2.push(x);
	id++;
	low[x]=id;
	for(int i:tu[x])
	{
		if(!low[i])
			dfs(i);
		else if(!scc[i])
			while(low[S2.top()]>low[i])
				S2.pop();
	}
	if(S2.top()==x)
	{
		S2.pop();
		cnt++;
		while(S1.top()!=x)
		{
			scc[S1.top()]=cnt;
			S1.pop();
		}
		scc[S1.top()]=cnt;
		S1.pop();
	}
	return ;
}
signed main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		tu[u].push_back(v);
	}
	for(int i=1;i<=n;i++)
		if(!low[i])
			dfs(i);
	for(int i=1;i<=n;i++)
		cout<<scc[i]<<'\n';
    return 0;
}
