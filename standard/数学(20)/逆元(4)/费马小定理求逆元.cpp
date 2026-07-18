#include<bits/stdc++.h>
#define int long long
using namespace std;
int qp(int x,int y)
{
	int sum=1,mod=y+2;
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
	int a,b;
	cin>>a>>b;
	cout<<qp(a,b-2);
	return 0;
}
//a*a^(m-2)同余1(mod m)(m为质数)
