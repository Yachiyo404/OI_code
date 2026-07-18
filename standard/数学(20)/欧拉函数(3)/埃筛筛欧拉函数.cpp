#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=4e4+5;
int phi[N],sum[N];
signed main()
{
	for(int i=1;i<N;i++)
		phi[i]=i;
	for(int i=2;i<N;i++)
	{
		if(phi[i]!=i)
			continue;
		for(int j=i;j<N;j+=i)
			phi[j]=phi[j]/i*(i-1);
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
