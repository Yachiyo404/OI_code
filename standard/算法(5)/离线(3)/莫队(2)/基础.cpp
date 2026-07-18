#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,k,B;
int ans[50005],a[50005],b[50005];
struct cxt{int l,r,id;}q[50005];
bool cmp(cxt x,cxt y)
{if((x.l-1)/B==(y.l-1)/B)return x.r<y.r;return x.l/B<y.l/B;}
void add(int x){c+=2*b[x]+1;b[x]++;return ;}
void del(int x){c-=2*b[x]-1;b[x]--;return ;}
signed main()
{
	int ans1=1,ans2=0;
	cin>>n>>m>>k;
	B=sqrt(n);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		cin>>q[i].l>>q[i].r;
		q[i].id=i;
	}
	sort(q+1,q+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int L=q[i].l,R=q[i].r;
		while(ans1>L)
		{
			ans1--;
			add(a[ans1]);
		}
		while(ans2<R)
		{
			ans2++;
			add(a[ans2]);
		}
		while(ans1<L)
		{
			del(a[ans1]);
			ans1++;
		}
		while(ans2>R)
		{
			del(a[ans2]);
			ans2--;
		}
		ans[q[i].id]=c;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<'\n';
	return 0;
}
