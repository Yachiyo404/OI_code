#include<bits/stdc++.h>
using namespace std;
int a[10005];
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			ans^=a[i];
		}
		if(ans==0)
			cout<<"No\n";
		else
			cout<<"Yes\n";
	}
    return 0;
}
