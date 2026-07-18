#include<bits/stdc++.h>
#define int long long
using namespace std;
struct cxt
{
	int l,r,h,bian;
}line[200005];
bool cmp(cxt x,cxt y){return x.h<y.h||(x.h==y.h&&x.bian>y.bian);}
int ls(int x){return x<<1;}
int rs(int x){return x<<1|1;}
int lz[800005],len[800005],num[800005];
bool L[800005],R[800005];
void pu(int x,int l,int r)
{
	if(lz[x])
	{
		L[x]=R[x]=1;
		len[x]=r-l+1;
		num[x]=1;
	}
	else if(l==r)
		len[x]=num[x]=L[x]=R[x]=0;
	else
	{
		L[x]=L[ls(x)];
		R[x]=R[rs(x)];
		len[x]=len[ls(x)]+len[rs(x)];
		num[x]=num[ls(x)]+num[rs(x)];
		if(L[rs(x)]&&R[ls(x)])
			num[x]--;
	}
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
	int mid=(tl+tr)>>1;
	if(l<=mid)
		up(ls(x),tl,mid,l,r,k);
	if(mid<r)
		up(rs(x),mid+1,tr,l,r,k);
	pu(x,tl,tr);
	return ;
}
signed main()
{
	int n,cnt=0,minn=1e5,maxn=-1e5;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x11,x12,y11,y12;
		cin>>x11>>y11>>x12>>y12;
		minn=min(minn,x11);
		maxn=max(maxn,x12);
		line[++cnt]=(cxt){x11,x12,y11,1};
		line[++cnt]=(cxt){x11,x12,y12,-1};
	}
	sort(line+1,line+cnt+1,cmp);
	int ans=0,lst=0;
	for(int i=1;i<=cnt;i++)
	{
		if(line[i].l<line[i].r)
			up(1,minn,maxn-1,line[i].l,line[i].r-1,line[i].bian);
		ans+=num[1]*2*(line[i+1].h-line[i].h);
		ans+=abs(len[1]-lst);
		lst=len[1];
	}
	cout<<ans;
	return 0;
}
