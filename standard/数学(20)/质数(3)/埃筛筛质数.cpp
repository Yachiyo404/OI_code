#include<bits/stdc++.h>
#define int long long
using namespace std;
bool vis[1000005];
signed main()
{
	memset(vis,1,sizeof(vis));
	vis[0]=0;vis[1]=0;
	for(int i=2;i<=1000000;i++)
	{
		if(!vis[i])
			continue;
		for(int j=i*2;j<=1000000;j+=i)
			vis[j]=0;
	}
	int n;
	cin>>n;
	if(vis[n])
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}
