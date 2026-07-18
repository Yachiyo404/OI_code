#include<bits/stdc++.h>
#define int long long
using namespace std;
int in[100005],out[100005],vis[100005];
vector<int>tu[100005];
stack<int>S;
void dfs(int x)
{
	for(int i=vis[x];i<tu[x].size();i=vis[x])
	{
		vis[x]=i+1;
		dfs(tu[x][i]);
	}
	S.push(x);
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
		in[v]++;
		out[u]++;
	}
	for(int i=1;i<=n;i++)
		sort(tu[i].begin(),tu[i].end());
	int cnt1=0,cnt2=0,s=1;
	bool flag=1;
	for(int i=1;i<=n;i++)
	{
		if(in[i]!=out[i])
		{
			flag=0;
			if(out[i]-in[i]==1)
			{
				cnt1++;
				s=i;
			}
			else if(in[i]-out[i]==1)
				cnt2++;
			else
			{
				cout<<"No";
				return 0;
			}
		}
	}
	if(!flag&&(cnt1!=1||cnt2!=1))
	{
		cout<<"No";
		return 0;
	}
	dfs(s);
	while(!S.empty())
	{
		cout<<S.top()<<" ";
		S.pop();
	}
	return 0;
}
