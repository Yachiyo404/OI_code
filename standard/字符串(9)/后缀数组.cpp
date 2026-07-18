#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,p;
int height[300005],rk[300005],oldrk[300005],sa[300005],id[300005],cnt[300005];
int main()
{
	cin>>s;
	n=s.size();
	s=' '+s;
	m=128;
	for(int i=1;i<=n;i++)
	{
		rk[i]=s[i];
		cnt[rk[i]]++;
	}
	for(int i=1;i<=m;i++)
		cnt[i]+=cnt[i-1];
	for(int i=n;i>=1;i--)
		sa[cnt[rk[i]]--]=i;
	for(int w=1;;w<<=1,m=p)
	{
		int cur=0;
		for(int i=n-w+1;i<=n;i++)
			id[++cur]=i;
		for(int i=1;i<=n;i++)
			if(sa[i]>w)
				id[++cur]=sa[i]-w;
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++)
			cnt[rk[i]]++;
		for(int i=1;i<=m;i++)
			cnt[i]+=cnt[i - 1];
		for(int i=n;i>=1;i--)
			sa[cnt[rk[id[i]]]--]=id[i];
		p=0;
		memcpy(oldrk,rk,sizeof(oldrk));
		for(int i=1;i<=n;i++)
		{
			if(oldrk[sa[i]]==oldrk[sa[i-1]]&&oldrk[sa[i]+w]==oldrk[sa[i-1]+w])
				rk[sa[i]]=p;
			else
				rk[sa[i]]=++p;
		}
		if(p==n)
			break;
	}
	for(int i=1;i<=n;i++)
		cout<<sa[i]-1<<" ";
	cout<<'\n';
	for(int i=1,k=0;i<=n;i++)
	{
		if(rk[i]==0)
			continue;
		if(k)
			--k;
		while(s[i+k]==s[sa[rk[i]-1]+k])
			++k;
		height[rk[i]]=k;
	}
	for(int i=1;i<=n;i++)
		cout<<height[i]<<" ";
	return 0;
}
