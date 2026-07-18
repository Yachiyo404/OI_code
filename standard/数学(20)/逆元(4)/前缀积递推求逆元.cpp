#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	int x=0,f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar())
		if(c=='-')
			f=-1;
	for(;isdigit(c);c=getchar())
		x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int qp(int x,int y,int mod)
{
	int sum=1;
	while(y)
	{
		if(y&1)
			sum=sum*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return sum;
}
int a[5000005],sum[5000005],inv[5000005];
signed main()
{
	int n=read(),p=read(),k=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	sum[0]=1;
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]*a[i]%p;//前缀积
	inv[n]=qp(sum[n],p-2,p);
	for(int i=n;i;i--)
		inv[i-1]=inv[i]*a[i]%p;//inv[i-1]同余inv[i]*a[i](mod p)
	int jc=1,num=0;
	for(int i=1;i<=n;i++)
	{
		int ans=sum[i-1]*inv[i]%p;//a[i].inv同余inv[i]*sum[i-1](mod p)
		jc=jc*k%p;
		num=(num+jc*ans)%p;
	}
	cout<<num;
	return 0;
}
