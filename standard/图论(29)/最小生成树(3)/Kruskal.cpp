#include<bits/stdc++.h>
#define int long long
using namespace std;
int fa[200005];
struct cxt
{
	int b,e,w;
}tu[200005];
bool cmp(cxt x,cxt y)
{
	return x.w<y.w;
}
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool ck(int x,int y)
{
	if(find(x)!=find(y))
		return 1;
	return 0;
}
void mg(int x,int y)
{
	x=find(x);
	y=find(y);
	fa[y]=x;
	return ;
}
signed main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
		cin>>tu[i].b>>tu[i].e>>tu[i].w;
	sort(tu+1,tu+m+1,cmp);
	int cnt=0,ans=0;
	for(int i=1;i<=m;i++)
	{
		if(ck(tu[i].b,tu[i].e))
		{
			mg(tu[i].b,tu[i].e);
			ans+=tu[i].w;
			cnt++;
			if(cnt==n-1)
			{
				cout<<ans;
				return 0;
			}
		}
	}
	cout<<"orz";
	return 0;
}
