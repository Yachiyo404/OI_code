#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int tree[1000005],jc[1000005];
int n,ans=1;
int lowbit(int x)
{
	return x&(-x);
}
void up(int i,int x)
{
	for(;i<=n;i+=lowbit(i))
		tree[i]+=x;
	return ;
}
int query(int i)
{
	int sum=0;
	for(;i;i-=lowbit(i))
		sum+=tree[i];
	return sum;
}
signed main()
{
	cin>>n;
	jc[0]=1;
	for(int i=1;i<=n;i++)
	{
		up(i,1);
		jc[i]=jc[i-1]*i%mod;
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		ans+=((query(k)-1)*jc[n-i]%mod);
		ans%=mod;
		up(k,-1);
	}
	cout<<ans;
	return 0;
}
//ans=1+sigma(A[i]*(n-i)!)(1<=i<=n)
//A[i]=sigma([a[j]<a[i]])(i<=j<=n)
