#include<bits/stdc++.h>
#define int long long
using namespace std;
int ten[15],dp[15],cnta[15],cntb[15],num[15];
void f(int x,int *cnt)
{
	int len=0;
	while(x)
	{
		num[++len]=x%10;
		x/=10;
	}
	for(int i=len;i;i--)
	{
		for(int j=0;j<=9;j++)
			cnt[j]+=dp[i-1]*num[i];
		for(int j=0;j<num[i];j++)
			cnt[j]+=ten[i-1];
		int sum=0;
		for(int j=i-1;j;j--)
			sum=sum*10+num[j];
		cnt[num[i]]+=sum+1;
		cnt[0]-=ten[i-1];
	}
	return ;
}
signed main()
{
	ten[0]=1;
	for(int i=1;i<=14;i++)
	{
		dp[i]=i*ten[i-1];
		ten[i]=10*ten[i-1];
	}
	int a,b;
	cin>>a>>b;
	f(a-1,cnta);
	f(b,cntb);
	for(int i=0;i<=9;i++)
		cout<<cntb[i]-cnta[i]<<" ";
	return 0;
}
