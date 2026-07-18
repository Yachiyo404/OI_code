#include<bits/stdc++.h>
#define int long long
using namespace std;
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
signed main()
{
	int a,b,p;
	cin>>a>>b>>p;
	int ans=qp(a,b,p);
	cout<<a<<"^"<<b<<" mod "<<p<<"="<<ans;
	return 0;
}
