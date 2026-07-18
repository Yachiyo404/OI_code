#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=4e4+5;
int phi[N],p[N],sum[N];
bool vis[N];
signed main()
{
	phi[1]=1;
	int cnt=0;
	for(int i=2;i<N;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			p[++cnt]=i;
			phi[i]=i-1;
		}
		for(int j=1;j<=cnt;j++)
		{
			if(i*p[j]>N)
				break;
			vis[i*p[j]]=1;
			if(i%p[j]==0)
			{
				phi[i*p[j]]=phi[i]*p[j];
				break;
			}
			phi[i*p[j]]=phi[i]*phi[p[j]];
		}
	}
	sum[1]=1;
	for(int i=2;i<N;i++)
		sum[i]=sum[i-1]+phi[i];
	int n;
	cin>>n;
	if(n==1)
		cout<<0;
	else
		cout<<2*sum[n-1]+1;
	return 0;
}
