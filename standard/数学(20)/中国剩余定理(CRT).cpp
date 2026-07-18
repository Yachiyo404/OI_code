#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,s;
int a[15],b[15];
int exgcd(int a,int b,int &x,int &y)
{
	if(!b)
	{
		x=1;
		y=0;
		return a;
	}
	int r=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return r;
}
signed main()
{
	cin>>n;
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		ans*=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k=ans/a[i],x,y;
		exgcd(k,a[i],x,y);
		s=(s+k*b[i]*x%ans)%ans;
	}
	cout<<(s+ans)%ans;
	return 0;
}
//K=pai(a[i])(1<=i<=n)
//m[i]=k/a[i]=pai(a[j])(1<=j<=n&&j!=i)
//k[i]=m[i].inv(mod a[i])
//x=sigma(b[i]*m[i]*k[i])(1<=i<=n)(mod K)
