#include<bits/stdc++.h>
using namespace std;
int d[100005],c[100005],st[100005][20],sum[100005][20];
stack<int>S;
int main()
{
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>d[i]>>c[i];
	for(int i=1;i<=n;i++)
	{
		while(!S.empty()&&d[i]>d[S.top()])
		{
			int x=S.top();
			S.pop();
			st[x][0]=i;
			sum[x][0]=c[i];
		}
		S.push(i);
	}
	while(!S.empty())
	{
		int x=S.top();
		S.pop();
		st[x][0]=0;
	}
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=1;i+(1<<j)<=n;i++)
		{
			st[i][j]=st[st[i][j-1]][j-1];
			sum[i][j]=sum[i][j-1]+sum[st[i][j-1]][j-1];
		}
	}
	while(q--)
	{
		int r,v;
		cin>>r>>v;
		if(c[r]>=v)
		{
			cout<<r<<'\n';
			continue;
		}
		v-=c[r];
		for(int j=18;j>=0;j--)
		{
			if(st[r][j]!=0&&v>sum[r][j])
			{
				v-=sum[r][j];
				r=st[r][j];
			}
		}
		cout<<st[r][0]<<'\n';
	}
	return 0;
}
