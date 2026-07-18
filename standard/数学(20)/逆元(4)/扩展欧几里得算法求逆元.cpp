#include<bits/stdc++.h>
#define int long long
using namespace std;
int exgcd(int a,int b,int &x,int &y)
{
	if(!b)
	{
		x=1;
		y=0;
		return a;
	}
	int d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
signed main()
{
	int a,b,x,y;
	cin>>a>>b;
	int g=exgcd(a,b,x,y);//a是原数,b是模数,x是逆元
	cout<<(x%b+b)%b;//防负数
	return 0;
}
