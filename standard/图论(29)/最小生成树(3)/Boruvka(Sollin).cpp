#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5005],fa[5005];
bool vis[200005];
struct cxt
{
	int b,e,w;
}tu[200005];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool ck(int x,int y)
{
	if(y==0)
		return 1;
	if(tu[x].w!=tu[y].w)
		return tu[x].w<tu[y].w;
	return x<y;
}
signed main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>tu[i].b>>tu[i].e>>tu[i].w;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	int cnt=0,sum=0;
	bool flag=1;
	while(flag)
	{
		flag=0;
		memset(a,0,sizeof(a));
		for(int i=1;i<=m;i++)
		{
			if(vis[i])
				continue;
			int p=find(tu[i].b),q=find(tu[i].e);
			if(p==q)
				continue;
			if(ck(i,a[p]))
				a[p]=i;
			if(ck(i,a[q]))
				a[q]=i;
		}
		for(int i=1;i<=n;i++)
			if(a[i]&&!vis[a[i]])
			{
				flag=1;
				cnt++;
				sum+=tu[a[i]].w;
				vis[a[i]]=1;
				fa[find(tu[a[i]].b)]=find(tu[a[i]].e);
			}
	}
	if(cnt==n-1)
		cout<<sum;
	else
		cout<<"orz";
	return 0;
}
