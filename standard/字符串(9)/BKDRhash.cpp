#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int a[10005];
int f(string s)
{
	int p=131,h=0,n=s.size();
	for(int i=0;i<n;i++)
		h=h*p+s[i]-'a'+1;
	return h;
}
signed main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		a[i]=f(s);
	}
	int ans=0;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		if(a[i]!=a[i-1])
			ans++;
	cout<<ans;
    return 0;
}
