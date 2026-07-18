#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	int n,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	int x;
    	cin>>x;
    	sum+=x;
	}
	if(sum%2)
		cout<<"Alice";
	else
		cout<<"Bob";
	return 0;
}
