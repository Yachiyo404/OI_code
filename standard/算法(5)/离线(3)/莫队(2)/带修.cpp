#include<bits/stdc++.h>
#define int long long
using namespace std;
int sum,cntq,cntr,n,m,B;
int cnt[1000005],a[150005],ans[150005];
struct cxt{int l,r,t,id;}qq[150005];
struct tsy{int l,r;}qr[150005];
void add(int x){if(!cnt[x])sum++;cnt[x]++;return ;}
void del(int x){cnt[x]--;if(!cnt[x])sum--;return ;}
void upd(int x,int t){if(qq[x].l<=qr[t].l&&qr[t].l<=qq[x].r){del(a[qr[t].l]);add(qr[t].r);}swap(a[qr[t].l],qr[t].r);return ;}
bool cmp(cxt a,cxt b){if(a.l/B==b.l/B){if(a.r/B==b.r/B)return a.t<b.t;return a.r<b.r;}return a.l<b.l;}
signed main()
{
	cin>>n>>m;
	B=pow(n,0.666);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		char op;
		int l,r;
		cin>>op>>l>>r;
		if(op=='Q')
		{
			cntq++;
			qq[cntq].id=cntq;
			qq[cntq].l=l;
			qq[cntq].r=r;
			qq[cntq].t=cntr;
		}
		else
		{
			cntr++;
			qr[cntr].l=l;
			qr[cntr].r=r;
		}
	}
	sort(qq+1,qq+cntq+1,cmp);
	int L=1,R=0,T=0;
	for(int i=1;i<=cntq;i++)
	{
		while(L>qq[i].l)
			add(a[--L]);
		while(L<qq[i].l)
			del(a[L++]);
		while(R>qq[i].r)
			del(a[R--]);
		while(R<qq[i].r)
			add(a[++R]);
		while(T<qq[i].t)
			upd(i,++T);
		while(T>qq[i].t)
			upd(i,T--);
		ans[qq[i].id]=sum;
	}
	for(int i=1;i<=cntq;i++)
		cout<<ans[i]<<'\n';
	return 0;
}
