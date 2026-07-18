#include<bits/stdc++.h>
#define int long long
#define d double
using namespace std;
d x[25],y[25],dis[25][25],dp[100005][25];
d Dis(d x,d y,d xx,d yy)
{
	return sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
}
signed main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			dis[i][j]=Dis(x[i],y[i],x[j],y[j]);
	memset(dp,91,sizeof(dp));
	for(int i=1;i<=n;i++)
		dp[(1<<(i-1))][i]=dis[i][0];
	for(int i=1;i<(1<<n);i++)
		for(int j=1;j<=n;j++)
		{
			if((i&(1<<(j-1)))==0)
				continue;
			for(int k=1;k<=n;k++)
			{
				if(j==k)
					continue;
				if((i&(1<<(k-1)))==0)
					continue;
				dp[i][j]=min(dp[i][j],dp[i^(1<<(j-1))][k]+dis[k][j]);
			}
		}
	d ans=1e18;
	for(int i=1;i<=n;i++)
		ans=min(ans,dp[(1<<n)-1][i]);
	cout<<fixed<<setprecision(2)<<ans;
	return 0;
}
