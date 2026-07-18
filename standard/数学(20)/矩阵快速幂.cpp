#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int n,k;
struct cxt
{
	int jz[105][105];
}a,b;
cxt operator*(cxt x,cxt y)
{
	cxt z;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			z.jz[i][j]=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				z.jz[i][j]=(z.jz[i][j]+x.jz[i][k]*y.jz[k][j]%mod)%mod;
	return z;
}
cxt qp(cxt x,int y)
{
	cxt sum=b;
	while(y)
	{
		if(y&1)
			sum=sum*x;
		x=x*x;
		y>>=1;
	}
	return sum;
}
signed main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a.jz[i][j];
	for(int i=1;i<=n;i++)
		b.jz[i][i]=1;
	b=qp(a,k);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<b.jz[i][j]<<" ";
		cout<<'\n';
	}
	return 0;
}
