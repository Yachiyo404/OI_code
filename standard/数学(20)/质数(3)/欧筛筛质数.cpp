#include<bits/stdc++.h>
#define int long long
using namespace std;
int p[1000005];
bool vis[1000005];
signed main()
{
	memset(vis,1,sizeof(vis));
	vis[0]=0;vis[1]=0;int cnt=0;
	for(int i=2;i<=1000000;i++)
	{
		if(vis[i])
			p[++cnt]=i;
		for(int j=1;j<=cnt;j++)
		{
			if(i*p[j]>1000000)
				break;
			vis[i*p[j]]=0;
			if(i%p[j]==0)
				break;
		}
	}
	int n;
	cin>>n;
	if(vis[n])
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}
