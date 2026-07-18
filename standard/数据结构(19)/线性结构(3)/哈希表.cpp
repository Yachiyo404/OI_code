#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
const int N=19260817;
LL h[N],kk[N];
bool f[N];
void insert(LL x,LL y)
{
	int k=x%N;
	while(f[k]==1)
	{
		if(kk[k]==x)
			break;
		k++;
		if(k==N)
			k=0;
	}
	kk[k]=x;
	h[k]=y;
	f[k]=1;
	return;
}
LL find(LL x)
{
	int k=x%N;
	while(f[k]==1)
	{
		if(kk[k]==x)
			return h[k];
		k++;
		if(k==N)
			k=0;
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin>>n;
	LL sum=0;
	for(int i=1;i<=n;i++)
	{
		LL x,y;
		cin>>x>>y;
		LL ans=i*find(x);
		sum+=ans;
		insert(x,y);
	}
	cout<<sum;
	return 0;
}
