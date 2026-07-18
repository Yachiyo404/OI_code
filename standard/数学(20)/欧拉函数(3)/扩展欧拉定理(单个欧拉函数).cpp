#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,mod;
int qp(int x,int y)
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
signed main()
{
	cin>>a>>mod;
	a%=mod;
	int m=mod,phi=mod;
	for(int i=2;i*i<=m;i++)
	{
		if(m%i)
			continue;
		phi=phi/i*(i-1);
		while(m%i==0)
			m/=i;
	}
	if(m>1)
		phi=phi/m*(m-1);
	int x=0;
	char c=getchar();
	bool flag=0;
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())
	{
		x=(x<<3)+(x<<1)+(c^48);
		if(x>=phi)
		{
			flag=1;
			x%=phi;
		}
	}
	if(flag)
		x+=phi;
	cout<<qp(a,x);
	return 0;
}
//欧拉定理:a,m属于Z,且gcd(a,m)=1 ---> a^fai(m)同余1(mod m)
//扩展欧拉定理:
//1.b<fai(m) ---> a^b同余a^b(mod m)
//2.b>=fai(m) ---> a^b同余a^(b%fai(m)+fai(m))(mod m)
