#include<bits/stdc++.h>
#define int long long
using namespace std;
int jc[100005],inv[100005];
int qp(int x,int y,int mod)
{
	int sum=1;
	while(y)
	{
		if(y&1)
		{
			sum*=x;
			sum%=mod;
		}
		x*=x;
		x%=mod;
		y>>=1;
	}
	return sum;
}
int C(int n,int m,int mod)
{
	if(n<m)
		return 0;
	if(n<mod&&m<mod)
		return jc[n]*inv[m]%mod*inv[n-m]%mod;
	return C(n/mod,m/mod,mod)*C(n%mod,m%mod,mod)%mod;
}
signed main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,m,p;
		cin>>n>>m>>p;
		n+=m;
		jc[0]=1;
		for(int i=1;i<=p-1;i++)
			jc[i]=jc[i-1]*i%p;
		inv[p-1]=qp(jc[p-1],p-2,p);
		for(int i=p-1;i;i--)
			inv[i-1]=inv[i]*i%p;
		cout<<C(n,m,p)<<'\n';
	}
	return 0;
}
//C m//nÍ¬ÓàC m/p//n/p*C m%p//n%p (mod p)
