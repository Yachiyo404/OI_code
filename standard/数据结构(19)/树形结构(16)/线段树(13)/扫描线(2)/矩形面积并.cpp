#include<bits/stdc++.h>
#define int long long
using namespace std;
int ls(int x){return x<<1;}
int rs(int x){return x<<1|1;}
int lz[800005],len[800005],xx[800005];
struct cxt
{
	int y,rx,lx,bian;
}line[200005];
bool cmp(cxt x,cxt y){return x.y<y.y;}
void pu(int x,int l,int r)
{
	if(lz[x])
		len[x]=xx[r]-xx[l];
	else if(l+1==r)
		len[x]=0;
	else
		len[x]=len[ls(x)]+len[rs(x)];
	return ;
}
void up(int x,int tl,int tr,int l,int r,int k)
{
	if(tl>=l&&tr<=r)
	{
		lz[x]+=k;
		pu(x,tl,tr);
		return ;
	}
	if(tl+1==tr)
		return ;
	int mid=(tl+tr)>>1;
	if(l<=mid)
		up(ls(x),tl,mid,l,r,k);
	if(mid<r)
		up(rs(x),mid,tr,l,r,k);
	pu(x,tl,tr);
	return ;
}
signed main()
{
	int n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x11,x12,y11,y12;
		cin>>x11>>y11>>x12>>y12;
		line[++cnt]=(cxt){y11,x12,x11,1};
		xx[cnt]=x11;
		line[++cnt]=(cxt){y12,x12,x11,-1};
		xx[cnt]=x12;
	}
	sort(xx+1,xx+cnt+1);
	sort(line+1,line+cnt+1,cmp);
	int num=unique(xx+1,xx+cnt+1)-(xx+1),ans=0;
	for(int i=1;i<=cnt;i++)
	{
		int l,r;
		ans+=len[1]*(line[i].y-line[i-1].y);
		l=lower_bound(xx+1,xx+num+1,line[i].lx)-xx;
		r=lower_bound(xx+1,xx+num+1,line[i].rx)-xx;
		up(1,1,num,l,r,line[i].bian);
	}
	cout<<ans;
	return 0;
}
