#include<bits/stdc++.h>
#define int long long
using namespace std;
int p[22000005];
char s[22000005];
string a;
signed main()
{
	cin>>a;
	int n=a.size();
	int k=0;
	s[k++]='$';
	s[k++]='#';
	for(int i=0;i<n;i++)
	{
		s[k++]=a[i];
		s[k++]='#';
	}
	s[k++]='&';
	n=k;
	int r=0,c;
	for(int i=1;i<n;i++)
	{
		if(i<r)
			p[i]=min(p[(c<<1)-i],p[c]+c-i);
		else
			p[i]=1;
		while(s[i+p[i]]==s[i-p[i]])
			p[i]++;
		if(p[i]+i>r)
		{
			r=p[i]+i;
			c=i;
		}
	}
	int ans=1;
	for(int i=0;i<n;i++)
		ans=max(ans,p[i]);
	cout<<ans-1;
	return 0;
}
