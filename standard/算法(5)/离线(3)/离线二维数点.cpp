#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int t[N];
int lb(int x){return x&(-x);}
void add(int i)
{
	for(;i<=N;i+=lb(i))
		t[i]++;
	return ;
}
int ask(int i)
{
	int sum=0;
	for(;i;i-=lb(i))
		sum+=t[i];
	return sum;
}//树状数组维护当前比x小的数的个数
int a[N],ans[N];
struct cxt{int x,id,val;};
vector<cxt>M[N];
signed main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		int l,r,x;
		cin>>l>>r>>x;
		M[l-1].push_back((cxt){x,i,-1});
		M[r].push_back((cxt){x,i,1});
	}
	for(int i=1;i<=n;i++)
	{
		add(a[i]);
		for(cxt j:M[i])
			ans[j.id]+=(j.val*ask(j.x));
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<'\n';
	return 0;
}
