#include<bits/stdc++.h>
#define int long long
using namespace std;
int inv[3000005],factinv[3000005];
signed main()
{
	int n,p;
	cin>>n>>p;
	factinv[1]=inv[1]=1;
	cout<<"1\n";
	for(int i=2;i<=n;i++)
	{
		inv[i]=(p-p/i)*inv[p%i]%p;//单个数逆元 
		cout<<inv[i]<<'\n';
		factinv[i]=factinv[i-1]*inv[i]%p;//阶乘逆元 
	}
	return 0;
}
